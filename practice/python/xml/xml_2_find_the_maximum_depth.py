#!/usr/bin/env python

from xml.etree.ElementTree import XMLParser

class MaxDepth:
    def __init__(self):
        self.maxDepth = 0
        self.depth = 0
    def start(self, tag, attrib):
        self.depth += 1
        if self.depth > self.maxDepth:
            self.maxDepth = self.depth
    
    def end(self, tag):
        self.depth -= 1
        
    def data(self, data):
        pass
    
    def close(self):
        return self.maxDepth - 1
    
target = MaxDepth()
parser = XMLParser(target=target)

n = int(raw_input().strip())
text = ''
for _ in range(n):
    line = raw_input().strip()
    text += line + '\n'

parser.feed(text)
print parser.close()

