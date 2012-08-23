#!/usr/bin/env python
import time
import os

class clicker:
	x=''
	y=''
	delay=''
	n=''

	def __init__(self,delay,n):
		self.delay=delay*60
		self.n=n
		self.getMouseLoc()

	def getMouseLoc(self):
		mouse=os.popen('xdotool getmouselocation').read()
		data=mouse.split(':')
		self.x=data[1].split()[0]
		self.y=data[2].split()[0]
		self.slideView()

	def slideView(self):
		for i in range(0,self.n):
			print "Slide "+str(i+1)
			time.sleep(self.delay)
			os.system('xdotool mousemove %s %s'%(self.x,self.y))
			os.system('xdotool click 1')
def main():
	n=int(os.popen('zenity --entry --text "Enter the number of slides " --title "Number"').read())
	delay=int(os.popen('zenity --entry --text "Enter the delay in minutes required between slides " --title "Delay"').read())
	os.system('zenity --info --text "POSITION,DONT CLICK mouse over the NEXT button of slide and press enter" --title "Main string"')
	c=clicker(delay,n)
main()
