import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public class EventInfo{
        int id;
        int x;
        int y;
        Integer price;
        EventInfo(int id, int x, int y, Integer price){
            this.id = id;
            this.x = x;
            this.y = y;
            this.price = price;
        }
    }
    public class PurchasedEvent{
        int distance = Integer.MAX_VALUE;
        EventInfo eventInfo;
        PurchasedEvent(Integer d, EventInfo eventInfo){
            this.eventInfo = eventInfo;
        }
    }
    public class BuyerInfo{
        int x;
        int y;
        PurchasedEvent purchasedEvent;
        public BuyerInfo(int x, int y, PurchasedEvent purchasedEvent){
            this.x = x;
            this.y = y;
            this.purchasedEvent = purchasedEvent;
        }
    }
    public static void main(String args[] ) throws Exception {
        Solution solution = new Solution();
        solution.compute();
    }    

    public void compute(){
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        Scanner scan = new Scanner(System.in);
        int sizeOfWorld = Integer.parseInt(scan.nextLine());
        int numberOfEvents = Integer.parseInt(scan.nextLine());
        List<EventInfo> events = new ArrayList<>();
        final EventInfo H =  new EventInfo(Integer.MAX_VALUE, sizeOfWorld+1, sizeOfWorld+1, Integer.MAX_VALUE);
        final PurchasedEvent HP = new PurchasedEvent(Integer.MAX_VALUE, H);
        while(numberOfEvents > 0){
            String eventLine = scan.nextLine();
            // TODO: you will need to parse and store the events 
            String[] paresedEvent = eventLine.split(" ");
            int id = Integer.parseInt(paresedEvent[0]);
            int x = Integer.parseInt(paresedEvent[1]);
            int y = Integer.parseInt(paresedEvent[2]);
            List<Integer> prices = new ArrayList<>();
            for(int i = 3; i<paresedEvent.length; i++)
                prices.add(Integer.parseInt(paresedEvent[i]));
            Collections.sort(prices);
            for(Integer price : prices)
                events.add(new EventInfo (id, x, y, price));
            numberOfEvents--;
        }
        
        List<BuyerInfo> buyers = new ArrayList<>();
        int numberOfBuyers = Integer.parseInt(scan.nextLine());
        while(numberOfBuyers > 0){
            String buyerLine = scan.nextLine();
            String[] parsedBuyer = buyerLine.split(" ");
            buyers.add(new BuyerInfo(Integer.parseInt(parsedBuyer[0]), Integer.parseInt(parsedBuyer[1]), HP));
            numberOfBuyers--;
        }

        for(BuyerInfo buyerInfo : buyers){
            List<EventInfo> discardedEvents = new ArrayList<>();
            for(EventInfo eventInfo : events){
                    int distanceToEvent = calculateManhattanDistance(buyerInfo.x, buyerInfo.y, eventInfo.x , eventInfo.y);
                    if(distanceToEvent<buyerInfo.purchasedEvent.distance){
                        discardedEvents.add(buyerInfo.purchasedEvent.eventInfo);
                        buyerInfo.purchasedEvent.distance = distanceToEvent;
                        buyerInfo.purchasedEvent.eventInfo = eventInfo;
                    }
                    else if(distanceToEvent == buyerInfo.purchasedEvent.distance){
                        if(eventInfo.price<buyerInfo.purchasedEvent.eventInfo.price){
                            discardedEvents.add(buyerInfo.purchasedEvent.eventInfo);
                            buyerInfo.purchasedEvent.eventInfo = eventInfo;
                        }
                        else if(eventInfo.price == buyerInfo.purchasedEvent.eventInfo.price){
                            if(eventInfo.id<buyerInfo.purchasedEvent.eventInfo.id){
                                discardedEvents.add(buyerInfo.purchasedEvent.eventInfo);
                                buyerInfo.purchasedEvent.eventInfo = eventInfo;
                            }
                        }
                    }
            }
            events.remove(buyerInfo.purchasedEvent.eventInfo);
            events.addAll(discardedEvents);
        }
        // The solution to the first sample above would be to output the following to console:
        // (Obviously, your solution will need to figure out the output and not just hard code it)
        for(BuyerInfo buyerInfo : buyers){
            System.out.print(buyerInfo.purchasedEvent.eventInfo.id);
            System.out.print(" ");
            System.out.print(buyerInfo.purchasedEvent.eventInfo.price);
            System.out.println("");
        }
        return;
    }
    
    // The following method get the manhatten distance betwen two points (x1,y1) and (x2,y2)
    public static int calculateManhattanDistance(int x1, int y1, int x2, int y2)    {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}
