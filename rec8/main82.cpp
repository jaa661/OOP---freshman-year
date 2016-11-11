/*
 * Recitation 7
 * Jacob Abbott
 * inheritance
 */

#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    Instrument(){}
    virtual
    void makeSound() =0;
private:
};

void Instrument::makeSound()  {
 cout << "To make a sound... blow on a mouthpiece of size"<<endl;
}
///////////////////////////////////////////////////////////////////////////////
class Brass : public Instrument {
public:
    Brass(int mysize) : size(mysize){}
    void makeSound() {
        cout << "To make a sound... blow on a mouthpiece of size "<< size <<endl;
    }
private:
    int size;
};

class String : public Instrument {
public:
    String(int mypitch) : pitch(mypitch){}
    void makeSound() {
       cout << "To make a sound... bow a string with pitch "<< pitch << endl;
       
    }
private:
    unsigned pitch;
};

class Percussion : public Instrument {
public:
    Percussion(){}
    void makeSound() {
       cout << "To make a sound... hit me " << endl;
    }
private:
};
///////////////////////////////////////////////////////////////////////////////
class Violin : public String {
public:
    Violin(int mypitch) : String(mypitch){}
    void makeSound() {
        String::makeSound();
    }
private:
    unsigned pitch;
};

class Cello : public String {
public:
    Cello(int mypitch) : String(mypitch){}
    void makeSound() {
        String::makeSound();
    }
private:
    unsigned pitch;
};
////////////////////////////////////////
class Trumpet : public Brass {
public:
    Trumpet(int mysize) : Brass(mysize){}
    void makeSound() {
        Brass::makeSound();
    }
private:
    int size;
};

class Trombone : public Brass {
public:
    Trombone(int mysize) : Brass(mysize){}
    void makeSound() {
        Brass::makeSound();
    }
private:
    int size;
};
/////////////////////////////////////
class Cymbal : public Percussion {
public:
    Cymbal(){}
    void makeSound() {
        cout << "To make a sound... tap me"<<endl;
    }
private:
};

class Drum : public Percussion {
public:
    Drum(){}
    void makeSound() {
        cout << "To make a sound... bang on me" <<endl;
    }
private:
};
////////////////////////////////////////////////////////////////////////////////
class Mill {
public:
	Mill() {}
	void receiveInstr( Instrument& i ) {
        i.makeSound();
        for (Instrument* temp : instruments){
                    if (temp == NULL){
                         temp = &i;
                         break;
                    }}
        instruments.push_back(&i);    
        }
        
	Instrument* loanOut( ) { 
          Instrument* loaner;
          loaner = instruments[0];
          instruments[0] = instruments.back();
          instruments.pop_back();
          if (loaner != NULL)
              return loaner;
          else{
            cout << "no available instruments were found"<<endl;
            Instrument* newinstr;
            return newinstr ;
          }}
        void dailyTestPlay(){
            for (Instrument* temp : instruments){
                temp->makeSound();
                }
        }
private:
	vector<Instrument*> instruments;
};

//////////////////////////////////////////////////////////////////////////////


class Musician {
public:
	Musician() : instr( NULL ) {}
	void acceptInstr( Instrument & i ) { instr = &i; }
	Instrument* giveBackInstr( ) { 
		Instrument* tmp(instr); 
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if( instr )
			instr->makeSound(); 
		else
			cerr << "have no instr\n";
	}
private:
	Instrument* instr;
};


//void makeSound(const Instrument instruments) {
//	instruments.displayNumPages();
//}

// PART ONE
int main()
{

   cout << "Define some instruments ----------------------------------------\n";
   Drum drum;
   Cello cello(673);
   Cymbal cymbal;
   Trombone tbone( 4 );
   Trumpet trpt( 12 ) ;
   Violin violin( 567 ) ;
  
   // use the debugger to look at the mill
   cout << "Define the MILL ------------------------------------------------\n";
   Mill mill;
  
   cout << "Put the instruments into the MILL ------------------------------\n";
   mill.receiveInstr( trpt );
   mill.receiveInstr( violin );
   mill.receiveInstr( tbone );
   mill.receiveInstr( drum );
   mill.receiveInstr( cello );
   mill.receiveInstr( cymbal );
  
   cout << "Daily test -----------------------------------------------------\n";
   cout << endl;
   cout << "dailyTestPlay()" << endl;
   mill.dailyTestPlay();
   cout << endl;
  
   cout << "Define some Musicians-------------------------------------------\n";
   Musician j;
   Musician jj;
   Musician q;
  	
   cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
  // q.testPlay();	
   //cout << endl;
   q.acceptInstr( *mill.loanOut() );
   //cout << endl;
   q.testPlay();
   cout << endl;
   cout << "dailyTestPlay()" << endl;
   mill.dailyTestPlay();
  
   cout << endl << endl;
  
   q.testPlay();	
   cout << endl;
   mill.receiveInstr( *q.giveBackInstr() );
   j.acceptInstr( *mill.loanOut() );
   q.acceptInstr( *mill.loanOut() );
   cout << endl;
   q.testPlay();
   cout << endl;
   j.testPlay();
   cout << endl;
   cout << "dailyTestPlay()" << endl;
   mill.dailyTestPlay();
  
   cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
  
   // fifth
   mill.receiveInstr( *q.giveBackInstr() );
   cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
   mill.receiveInstr( *j.giveBackInstr() );

  
   cout << endl;
   cout << "dailyTestPlay()" << endl;
   mill.dailyTestPlay();
   cout << endl;
  
   cout << endl;

}
