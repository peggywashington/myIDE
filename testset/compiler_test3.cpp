void delay()
{
	int c;c=30000;
	while(c>0){c=c-1;}
}
void main(){
	int led; 
	led=0;

	led=led+1;
	$0xfffffc60=led;
	if(led>10) led=0;
	delay();

}