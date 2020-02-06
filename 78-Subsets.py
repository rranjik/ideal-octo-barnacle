class Solution:
    def ss(self, nums, index, whatever, another_whatever):
        if(index==len(nums)):
            print(index, whatever)
            #aaw = whatever.copy()
            #another_whatever.append(aaw)
            another_whatever.append(whatever.deepcopy())
            return
        else:
            self.ss(nums,index+1,whatever,another_whatever)
            whatever.append(nums[index])
            self.ss(nums,index+1,whatever,another_whatever)
            del whatever[-1]
        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        whatever = []
        another_whatever = []
        self.ss(nums,0,whatever,another_whatever)
        return another_whatever
