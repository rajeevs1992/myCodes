import os
import sys
def createDirs():
	return os.system("mkdir "+sys.argv[1]+" "+sys.argv[2]+" && clear")
def fileList():
	list=''
	for i in os.popen("ls").read().split("\n"):
		if i.endswith(".mp3"):
			list+=i+" "
	return list.split("\n")
def getKey():
	return os.popen("./getch")
def sorter():
	list=fileList()
	createDirs()
	ch='0'
	for i in list:
		os.system("clear")
		print ''' Welcome to sorter!!!! 
			  LEFT directory :'z'
			  RIGHT directory:'m' 
			  SKIP           :'s' '''
		while ch not in 'z m s':
			print "LEFT "+sys.argv[1]+" RIGHT "+sys.argv[2]
			print "CURRENT FILE :"+i
			ch=getKey()
			if ch=='z':
				system("mv "+i+" "+sys.argv[1])
			elif ch=='m':
				system("mv "+i+" "+sys.argv[2])
			if ch=='s':
				system("clear")
			else
				print "Invalid"
if __name__=='__main__':
	sorter()
