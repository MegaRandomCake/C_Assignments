
union myUnion {
	int x, y;
};

int main(){
	union myUnion u;
	u.x = 2;
	u.y = 10;
	printf("X: %d, Y: %d\n", u.x, u.y);
	return 0;
}



/*
X: 10, Y: 10
This is because a union stores everything on the same memory space.
For this to work use a struct. However unions are smart as long as we are only using 1 thing at a time.

Also use
typedef union {
	int x, y;
} myUnion;

myUnion u;
 */
