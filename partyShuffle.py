import os
import random
def rename():
	alphaList=''
	os.chdir('/media/New Volume')
	dirList=os.listdir('.')
	num=len(dirList)
	for i in range(num):
		alphaList+=chr(random.randint(97,122))+' '
	alphaList=alphaList.split()
	for i in range(num):
		os.rename(dirList[i],alphaList[i]+dirList[i])
	os.listdir('.')
rename()
