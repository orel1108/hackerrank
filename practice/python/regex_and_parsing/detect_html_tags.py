#!/usr/bin/env python

from HTMLParser import HTMLParser

class TagHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print tag
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

