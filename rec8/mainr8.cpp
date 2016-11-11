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
    virtual
    void play() =0;
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
    void play(){}
private:
    int size;
};

class String : public Instrument {
public:
    String(int mypitch) : pitch(mypitch){}
    void makeSound() {
       cout << "To make a sound... bow a string with pitch "<< pitch << endl;  
    }
    void play(){}
private:
    unsigned pitch;
};

class Percussion : public Instrument {
public:
    Percussion(){}
    void makeSound() {
       cout << "To make a sound... hit me " << endl;
    }
    void play(){}
private:
};
///////////////////////////////////////////////////////////////////////////////
class Violin : public String {
public:
    Violin(int mypitch) : String(mypitch){}
    void makeSound() {
        String::makeSound();
    }
    void play(){
        cout << "screech";
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
    void play(){
        cout << "squawk";

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
    void play(){
        cout<< "toot";
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
    void play() {
        cout <<"blat";
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
    void play(){    
        cout<<"crash";
    }
private:
};

class Drum : public Percussion {
public:
    Drum(){}
    void makeSound() {
        cout << "To make a sound... bang on me" <<endl;
    }
    void play(){
        cout << "boom";
    }
private:
};
////////////////////////////////////////////////////////////////////////////////
class Mill {
public:
	Mill() {}
	void receiveInstr( Instrument& i ) {
        //i.makeSound();
        for (Instrument*& temp : instruments){
                    if (temp == NULL){
                         temp = &i;
                         return;
                    }}
        instruments.push_back(&i);    
        }
        
	Instrument* loanOut( ) { 
          Instrument* loaner;
          for (Instrument*& temp: instruments){
              if (temp != NULL){
                  loaner = temp;
                  temp = NULL;
                  return loaner;
              }}
            cout << "no available instruments were found"<<endl;
            return NULL ;
          }
        void dailyTestPlay(){
            for (Instrument* temp : instruments){
                if(temp != NULL)
                    temp->makeSound();
                else{
                    cout << "instrument placeholder"<<endl;
                }
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
        void play() const {
		if( instr )
			instr->play(); 
		else
			cerr << "";
	}
private:
	Instrument* instr;
};

/////////////////////////////////////////////////////////////////////////////

class Orch {
public:
	Orch(){}
	void addPlayer(Musician& newMusician) { 
            if (orchestra.size() < 25)
                orchestra.push_back(&newMusician);
            else
                cout << "sorry, but the orchestra is full"<<endl;
	}
	void play()  {
            for(Musician* musicman : orchestra){
                //cout <<"IM not WORKING HERE"<<endl;
                musicman->play();
                //cout <<"IM WORKING HERE"<<endl;
            }
            cout<<endl;
	}
private:
	vector<Musician*> orchestra;
};

//////////////////////////////////////////////////////////////////////////////
//void makeSound(const Instrument instruments) {
//	instruments.displayNumPages();
//}

// PART ONE

// PART TWO
int main()
{
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone( 4 );
	Trumpet trpt( 12 ) ;
	Violin violin( 567 ) ;

	Mill mill;
	mill.receiveInstr( trpt );
	mill.receiveInstr( violin );
	mill.receiveInstr( tbone );
	mill.receiveInstr( drum );
	mill.receiveInstr( cello );
	mill.receiveInstr( cymbal );

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr( *mill.loanOut() );
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr( *mill.loanOut() );

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr( *mill.loanOut() );
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr( *ralph.giveBackInstr() );

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr( *mill.loanOut() );
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr( *mill.loanOut() );

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
	
	// bob gets an instrument from the MIL2
	bob.acceptInstr( *mill.loanOut() );

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr( *mill.loanOut() );

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

} // main
