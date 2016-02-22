#!/usr/bin/env python

from HTMLParser import HTMLParser

class TagHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print "Start :", tag
        if attrs:
            for KEY_VAL in attrs:
                print '->', KEY_VAL[0], '>', KEY_VAL[1]
    
    def handle_endtag(self, tag):
        print "End   :", tag
    
    def handle_startendtag(self, tag, attrs):
        print "Empty :", tag
        if attrs:
            for KEY_VAL in attrs:
                print '->', KEY_VAL[0], '>', KEY_VAL[1]

n = int(raw_input().strip())
text = ''
for _ in range(n):
    line = raw_input().strip()
    text += line

parser = TagHTMLParser()
parser.feed(text)

