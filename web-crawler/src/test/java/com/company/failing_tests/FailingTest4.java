package com.company.failing_tests;

import com.company.crawler.Crawler;
import com.company.crawler.WebsiteGraph;
import com.company.loggers.VerboseCrawlerLogger;
import com.company.TestCase;

public class FailingTest4 extends TestCase {
	public static void main(String args[]) throws Exception {
		Crawler crawler = new Crawler(10, new VerboseCrawlerLogger());
		crawler.crawl("http://triplebyte.github.io/web-crawler-test-site/test4/", true);

		assertNotNull(crawler.graph.get("http://triplebyte.github.io/web-crawler-test-site/test4/page3"));

        System.out.println("Everything passed! Exceptional!");
	}
}
