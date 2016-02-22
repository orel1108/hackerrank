#!/usr/bin/env python

from xml.etree.ElementTree import XMLParser

class MaxDepth:
    def __init__(self):
        self.Score = 0
    def start(self, tag, attrib):
        self.Score += len(attrib)
    
    def end(self, tag):
        pass
        
    def data(self, data):
        pass
    
    def close(self):
        return self.Score
    
target = MaxDepth()
parser = XMLParser(target=target)

n = int(raw_input().strip())
text = ''
for _ in range(n):
    line = raw_input().strip()
    text += line + '\n'

parser.feed(text)
print parser.close()

