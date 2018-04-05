#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

bool isPrime(long int prime);
long int calculateE( long int t );
long int greatestCommonDivisor( long int e, long int t );
long int calculateD( long int e, long int t );
long int encrypt( long int i, long int e, long int n );
long int decrypt(long int i, long int d, long int n );

int main( )
{
    long int  p,q,n, z, e, d;
    bool flag;
    string msg;
	 cout << "*****************************************\n";
	 cout << "|       Welcome to RCS program          |" <<endl;
     cout << "*****************************************\n";
    /*do
    {
        cout << "Enter a Prime number  p :";
        cin >> p;
        flag = isPrime( p );
        if ( flag == false )
        {
            std::cout << "\nWRONG INPUT (This number is not Prime.)\n" << endl;
        }
    } while ( flag == false );
    
    do
    {
		cout << "Enter a Prime number  q :";
        cin >> q;
        flag = isPrime( q );
        
        if ( flag == false )
        {
            std::cout << "\nWRONG INPUT (This number is not Prime.)\n" << endl;
        }
    } while ( flag == false);*/
bool boolean = false;
long int num = 0;
long int ran[100];
long int number = 0;
long int a_e[100];

for(int i=2; i<=15;i++){
	boolean = true;
	for(int j=2;j<i;j++){
		if(i % j == 0){
			boolean = false;
			break;
		}
	}
	if(boolean){
		ran[number] = i;
		if(i == 2){
			//cout << "Specific Number : " << ran[number];
			number++;
			num++;
		}else{
			//cout <<  " , " << ran[number];	
			number++;
			num++;
		}
	}
}

bool boolean1 = false;
long int num1 = 0;
long int ran3[100];
long int number1 = 0;
long int a_e1[100];

for(int i=5; i<=15;i++){
	boolean1 = true;
	for(int j=2;j<i;j++){
		if(i % j == 0){
			boolean1 = false;
			break;
		}
	}
	if(boolean1){
		ran3[number1] = i;
		if(i == 5){
			//cout << "Specific Number : " << ran3[number1];
			number1++;
			num1++;
		}else{
			//cout <<  " , " << ran3[number1];	
			number1++;
			num1++;
		}
	}
}

	cout << endl;
	srand (time(NULL));
	long int ran1 = rand() % num;
	long int ran2 = rand() % num1;
	//long double e = 2;
     p = ran[ran1];
     q = ran3[ran2];
		/* if(q < 5){
			 do{
				srand (time(NULL));
				q = ran[ran2];
				//cout << "PP -> " << q <<endl;
				break;
			}while(p < 5);
		 }*/
	  if(p == q){
			//do{
				srand (time(NULL));
				q = ran[ran2];
				//cout << "PP -> " << q <<endl;
			//}while(p==q);
		}
	/*p = 7;
    q = 19;*/
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
    n = p * q;
    cout << "n = " << n << endl;
    
    z = ( p - 1 ) * ( q - 1 );
    cout << "z = " << z << endl;
    
	cout << "\n*****************************************\n";
    e = calculateE( z );
    
    
    d = calculateD( e, z );
    
    
    cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" << endl;
    long double c = 0;
			   //e = e % 10;
			   c = pow(long double(p),long double(e));
			   c = long int(c) % n;
	cout << "RSA C : " << c <<endl;
   
    cout << "\nRSA private key is (n = " << n << ", d = " << d << ")" << endl;
	long double pain = 0;
			   d = d % 10;
			   pain = pow(long double(c),long double(d));
			   pain = long int(pain) % n;
	//fmodl(long double pain, long double n);
	cout << "RSA P : " << pain <<endl;
	cout << "\n*****************************************\n";
	cout << "Enter Message : " ;
	cin >> msg;
	long int encryptedText[100];
    memset(encryptedText, 0, sizeof(encryptedText));
    
    long int decryptedText[100];
    memset(decryptedText, 0, sizeof(decryptedText));

	for (long int i = 0; i < msg.length(); i++)
    {
        encryptedText[i] = encrypt( msg[i], e, n);
		//cout << "MM => "<<encryptedText[i]<<endl;
		//cout << "MM => "<< int(msg[i])<<endl; 
    }
    
    cout << "\nTHE ENCRYPTED MESSAGE IS:" << endl;
    
    for ( long int i = 0; i < msg.length(); i++ )
    {
        //printf( "%n", (int)encryptedText[i] );
		if(encryptedText[i] <= 20 && encryptedText[i] >= 0){
			cout << encryptedText[i] ;
		}else{
			cout << char(encryptedText[i]);
		}
		//encryptedText[i] = 10;
		//cout << "test => " << char(encryptedText[i]) << endl;
    }
    cout << endl;
    
    //decryption
    
    for (long int i = 0; i < msg.length(); i++)
    {
        decryptedText[i] = decrypt(encryptedText[i], d, n);
    }
    
    cout << "\n\nTHE DECRYPTED MESSAGE IS:" << endl;
    
    for (long int i = 0; i < msg.length(); i++)
    {
        printf( "%c", (char)decryptedText[i] );
    }
    
    
	cout <<endl;
	/*int ass = 10;
	for(int a = 0 ; a <= 126 ; a++){
		cout << "as -> " << char(a) <<endl;
	}*/
	
    return 0;
}

bool isPrime( long int prime)
{
    long int i, j;
    
    j = (long int)sqrt((long double)prime);
    
    for ( i = 2; i <= j; i++)
    {
        if ( prime % i == 0 )
        {
            return false;
        }
    }
    
    return true;
}
long int calculateE( long int z )
{
    long int e;
    for ( e = 2; e < z; e++ )
    {
        if (greatestCommonDivisor( e, z ) == 1 )
        {
            return e;
        }
    }
    
    return -1;
}

long int greatestCommonDivisor( long int e, long int t )
{
    while ( e > 0 )
    {
        long int myTemp;
        
        myTemp = e;
        e = t % e;
        t = myTemp;
    }
    
    return t;
}

long int calculateD( long int e, long int t)
{
    long int d;
    long int k = 1;
    
    while ( 1 )
    {
        k = k + t;
        
        if ( k % e == 0)
        {
            d = (k / e);
            return d;
        }
    }
    
}
long int encrypt( long int i, long int e, long int n )
{
    long int current, result;
    //cout << "i -> "<<i<<endl;
    current = i - 97;
    result = 1;
    
    for ( long int j = 0; j < e; j++ )
    {
        result = result * current;
        result = result % n;
		
    }
    //cout << "result : " << result << endl;
    return result;
}

long int decrypt(long int i, long int d, long int n)
{
    long int current, result;
    
    current = i;
    result = 1;
    
    for ( long int j = 0; j < d; j++ )
    {
        result = result * current;
        result = result % n;
    }
    
    return result + 97;
}