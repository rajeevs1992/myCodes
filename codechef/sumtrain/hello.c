// Rainer Hoette, Paderborn, Germany
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a)>(b) ? (a) : (b))

static char _rbuf[8192*8];
static char *_rend = 0;
static char *_rpos = 0;
static int _getchar() {
	int n = read(0,_rbuf,sizeof _rbuf);
	if (n <= 0) {
		printf("EOF(%d)\n",n); exit(1);
	}
	_rend = _rbuf + n;
	_rpos = _rbuf+1;
	return *_rbuf;
}

#define mygetchar() ((_rpos<_rend)?*_rpos++:_getchar())

// inline int get_i() __attribute__((always_inline));
static int get_i() {
	int c;
	while (((c = mygetchar())) < '0') {}
	int n = c-'0';
	while (((c = mygetchar())) >= '0') {
		// if (c>'9') return n;
		n = n*10 + c - '0';
	}
	return n;
}

static void put_i(int n) {
#define BSIZE 16
	char buf[BSIZE];
	int bn = BSIZE-1;
	while (1) {
		buf[bn--] = '0'+(n%10);
		n = n / 10;
		if (n == 0) break;
	}
	while (bn<BSIZE-1) putchar(buf[++bn]);
	putchar('\n');
}

static int dump(int a[], int n) {
	int i=0;
	printf("line-dump:");
	while (i<n) printf("%d ",a[i++]);
	printf("\n");
}

void tria (int n) {
	int a[n];
	int b[n];
	// int z; for (z=0;z<n;z++) {a[z] = 99; b[z] = 99;}
	a[0] = 0;
	int *cur = b;
	int *old = a;
	int i=0;
	while (i<n) {
		cur[0] = get_i() + old[0];
		int j=1;
		while (j<i) {
			cur[j] = get_i() + max(old[j-1],old[j]);
			j++;
		}
		if (i) cur[j] = get_i() + old[j-1];
		if (cur == b) {
			cur = a;
			old = b;
		} else {
			cur = b;
			old = a;
		}
		i++;
	}
	// dump(old,n);
	int mx = 0;
	for (i=0;i<n;i++) mx = max(mx, old[i]);
	put_i(mx);
}

int main(int ac, char **av) {
	// int i=0,r; while (((r=read(0,_rbuf,sizeof _rbuf))) > 0) { i = i + r;} printf("readed=%d bufs\n",i);  // at 800MHZ: 0.000-0.004 user time
	// int i=0,r; while (1) {mygetchar();}; printf("fertig\n"); exit(0); // at 800MHZ: 0.044
	// int i=0,r; while (1) {get_i();} exit(0); // at 800MHZ: 0.052
	// algorithm at 800MHZ: 0.056

	int n = get_i();
	while (n-- > 0) {
		tria(get_i());
	}
	return 0;
}
