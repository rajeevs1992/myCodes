import os


def findDot(fileName):
        index=0
        while fileName[index:].find(".")!=-1:
		print index
                index=fileName.find(".")
        return index




filePath=raw_input("\nEnter the target folder ")
print filePath
extList=[]
if os.path.exists(filePath):
	fileList=os.listdir(filePath)
else:
	print "Error in path name"
for i in fileList:
	print i
	ind=findDot(i)
	extList.append(i[ind+1:])
print extList

