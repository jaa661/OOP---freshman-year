/*
 * Recitation 7
 * Jacob Abbott
 * inheritance
 */

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial( unsigned pages) : numberOfPages(pages){}
    virtual
    void displayNumPages() const =0;
private:
    unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
  cout << numberOfPages << endl << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine( unsigned pages) : PrintedMaterial(pages){}
    void displayNumPages() const  {
        cout << "Pages: "<< endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book( unsigned pages) : PrintedMaterial(pages){}
    void displayNumPages() const  {
        cout << "Pages: "<< endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class TextBook : public Book {
public:
	TextBook( unsigned pages, unsigned numIndxPgs  )
		: Book(pages), numOfIndexPages(numIndxPgs){}
	void displayNumPages() const
	{
        cout << "Pages: "<< endl;
        PrintedMaterial::displayNumPages();
        cout << "Index Pages: " << endl;
	cout << numOfIndexPages << endl;
        
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel( unsigned pages) : Book(pages){}

protected:
private:
};

void displayNumberOfPages( const PrintedMaterial& anyPM ) {
	anyPM.displayNumPages();
}

// tester/modeler code
int main()
{
    TextBook t(5430, 23);
    Novel n(213);
    Magazine m(6);

    //vector<PrintedMaterial> pmv;  // notyet
    //pmv.push_back(t);

    //cout << "\nA PrintedMaterial material object!\n";
    //PrintedMaterial pm(2345);
    //pm->displayNumPages();

    //cout << "\nA PrintedMaterial variable containing a TextBook value\n";
    //pm = t; // like putting a t into a vector of PrintedMaterials
    //pm.displayNumPages();    
    
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    
    //cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
    //cout << "Now with the virtual mechanism involved\n";
        // should work now that the virtual mechanism is being invoked
   // PrintedMaterial* pmPtr;
   // pmPtr = &t; // like putting a t into a vector
        // of pointers to PrintedMaterial
        // (that is, pointers to the Base class)
    //pmPtr->displayNumPages();
    
    vector<PrintedMaterial*> pmv;

    pmv.push_back(&t);
    pmv.push_back(&n);
    pmv.push_back(&m);
    for(PrintedMaterial* placeHolder: pmv){
        placeHolder->displayNumPages();
	cout << endl;
    }
}