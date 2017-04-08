static int a;
extern int b;

extern void ext();

void bar()
{
    a = 1; //inner-module data access
    b = 2; //inter-module data access 
}

void foo()
{
    bar(); //inner-module call
    ext(); //inter-module call
}
