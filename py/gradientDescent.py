import MySQLdb
import math
def getTrainingSet(tableName):
	con=MySQLdb.connect("localhost","root","password","exp")
	cursor=con.cursor()
	cursor.execute("SELECT * FROM %s"%(tableName))
	TrainingSet=cursor.fetchall()
	con.close()
	return TrainingSet
data=getTrainingSet("house")
def gradientDescent(learningRate,x0,x1):
	while 1:
		
		a=x0
		b=x1
		derx0=der_x0(x0,x1)
		derx1=der_x1(x0,x1)
		temp0=x0-learningRate*derx0
		temp1=x1-learningRate*derx1
		x0=temp0
		x1=temp1
def der_x0(x0,x1):
	sum=0.0
	global data
	m=len(data)
	for i in data:
		sum+=h(i[0],x0,x1)-i[1]
	sum/=m
	return sum
def der_x1(x0,x1):
	sum=0.0
	global data
	m=len(data)
	for i in data:
		sum+=(h(i[0],x0,x1)-i[1])*i[0]
	sum/=m
	return sum
def h(x,x0,x1):
	return x0+(x*x1)
def main():
	gradientDescent(int(raw_input("Enter learning rate ")),0.0,0.0)
if __name__=='__main__':
	main()

