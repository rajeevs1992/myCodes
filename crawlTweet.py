import twitter
import urllib2
import MySQLdb
api=twitter.Api()
statsList=[]
owner=[]
visited=''
c=0
def crawl(user):
	global visited,statsList,api,owner,c
	visited+=user+" "
	print str(c)+" "+user
	if c==2:
		stop(statsList,owner)
		exit(0)
	try:
		stats=api.GetUserTimeline(user)
		statsList.insert(c,stats)
		owner.insert(c,user)
		stats=[i.text for i in stats]
	except urllib2.HTTPError:
		return
	for i in stats:
		if i.startswith("@"):
			u=i.split()[0][1:]
			if u not in visited:
				c=c+1
				crawl(u)
def stop(l,owner):
	cursor=MySQLdb.connect("localhost","root","password","exp").cursor()
	query="CREATE TABLE data (tweet varchar(140),owner varchar(50))"
	cursor.execute(query)
	c=0
	for i in l:
		currentUser=owner[c]
		c=c+1
		for j in i:
			text=MySQLdb.escape_string(j.text)
			cursor.execute("""INSERT INTO data VALUES("%s","%s")"""%(text,currentUser))
	print "done"
def main():
	BaseUser=(raw_input("Enter the base user name "))
	crawl(BaseUser)
main()
