#include<iostream>
using namespace std;

template<class T>
class Linkedlist
{
public:
	Linkedlist();
	~Linkedlist();
	Linkedlist(Linkedlist &list1);
	void createCell(T value);
	void showAllValue()const;
	int numOfValue();
	bool isEmpty()const;
	void cutCell(Linkedlist &list1, int percent);
	void shuffle(Linkedlist &list1, int percent);
	void backShuffle(Linkedlist &list1, int percent);
private:
	struct Cell
	{
		T data;
		Cell *link;
	};
	Cell *start;
	Cell *cursor;
};

	template<class T>
	Linkedlist<T> :: Linkedlist()
	{
		start = cursor = new Cell;
		start->link = nullptr;
		cout << "****** Create Linklist + Create start and cursor. ***********\n\n\n" << endl;
	}

	template<class T>
	Linkedlist<T> :: ~Linkedlist()
	{
		cout << "\n\n\n----------Call destructor---------" << endl;
		Cell *cp = start;
		Cell *next ;
		while(cp != NULL)
		{
			next = cp->link;
			cout << "Delete" << cp->data << endl;
			delete cp;
			cp = next;
		}
		cout << "Delete Cell Complete." << endl;
	}

	template<class T>
	Linkedlist<T> :: Linkedlist(Linkedlist &list1)
	{
		int num = 1;
		start = cursor = new Cell;
		start->link = nullptr;
		Cell *ptrList1 = list1.start;
		ptrList1 = ptrList1->link;
		while(num <= list1.numOfValue())
		{
			Cell *newCell = new Cell;
			newCell->link = nullptr;
			newCell->data = ptrList1->data;
			cursor->link  = newCell;
			cursor = newCell;
			ptrList1 = ptrList1->link;
			num++;
		}
		cout << "Copy Constructor success." << endl;
	}

	template<class T>
	void Linkedlist<T> :: createCell(T value)
	{
		Cell *newCell = new Cell;
		newCell->data = value;
		newCell->link = nullptr;
			cursor->link = newCell;
			cursor = newCell;
		cout << "------- Create " << newCell->data << "   Success. ---------" << endl;
	}

	template<class T>
	void Linkedlist<T> :: showAllValue()const
	{
		Cell *ptr = start;
		ptr  = ptr->link;
		while(ptr != cursor)
		{
			cout << ptr->data << endl;
			ptr  = ptr->link;
		}
		cout << ptr->data << endl;
	}

	template<class T>
	int Linkedlist<T> :: numOfValue()
	{
		int count=0;
		Cell *np = start;
		while(np != cursor)
		{
			np = np->link;
			count++;
		}
		return count;
	}

	template<class T>
	bool Linkedlist<T> :: isEmpty()const
	{
		return cursor == start;
	}

	template<class T>
	void Linkedlist<T> :: cutCell(Linkedlist &list1, int percent)
	{
		//check percent
		if(percent <0 && percent >100)
		{
			cout << "percent <0 or >100 ." << endl;
		}
		else
		{
			// Convert percent in one digit.
			double per = (list1.numOfValue()*percent)/100 ;
			if((list1.numOfValue()*percent)%100 >= 50)
			{
				per++;
			}
			cout << "Cut " << per << endl;
			
			Cell *np = start;
			int count = 0;
			cursor->link = start->link; //10 -> 1
			//start -> 4
			while(count != per)
			{
				np = np->link;
				count++;
			}
			Cell *cp = np->link;
			start->link = cp;
			np->link = nullptr;
			while(cursor->link!=nullptr)
			{
				cursor = cursor->link;
			}
			cout << "Cut OK..." << endl;
		}
	}

	template<class T>
	void Linkedlist<T> :: shuffle(Linkedlist &list1, int percent)
	{
		// Check percent.
		if(percent <0 && percent >100)
		{
			cout << "percent <0 or >100 ." << endl;
		}
		else
		{
			// Convert percent in one digit.
			int per = (list1.numOfValue()*percent)/100 ;
			if((list1.numOfValue()*percent)%100 >= 50)
			{
				per++;
			}
			cout << "Cut " << per << "  and shuffle." << endl;
			
			//Craete numlink that refer number of link in shuffle.
			int number = list1.numOfValue();
			int sublink = number-per;
			int numlink;
			if(sublink<per)
			{
				numlink = 2*sublink;
			}
			else
			{
				numlink = 2*per-1;
			}

			cout << "numlink => " << numlink << endl;
			
			//Start shuffle create *before *after *tempbefore *tempafter
			Cell *before = start->link;
			Cell *after = before;
			int count=0;
			while(count != per)
			{
				after = after->link;
				count++;
			}
			Cell *tempbefore = before->link;
			Cell *tempafter = after->link;

			cout << "After =>  " << after->data << endl;
			
			// i is count of link that is i == numlink llinklist is break. 
			// ========== Jump ==========
			int i=0;
			while(true)
			{
				before->link = after;
				i++;
				if(i==numlink)break;
				after->link = tempbefore;
				i++;
				if(i==numlink)break;
				before = tempbefore;
				tempbefore = tempbefore->link;
				after = tempafter;
				tempafter = tempafter->link;

			}

			// run other link in linklist. 
			// ======= continue ==============
			if(per>5)
			{
				cursor = tempbefore;
				int remain = number-numlink-1;
				cout << "remain " << remain << endl;
				for(int i=0; i<remain; i++)
				{
					cursor = cursor->link;
				}
				cout << "cursor  " << cursor->data << endl;
				cursor->link = nullptr;
			}
			else
			{
				cursor = after;
				int remain = number-numlink-1;
				cout << "remain " << remain << endl;
				for(int i=0;i<remain;i++)
				{
					cursor = cursor->link;
				}
				
				cout << "cursor  " << cursor->data << endl;
				cursor->link = nullptr;
			}
		}
	}
	
	
	template<class T>
	void Linkedlist<T> :: backShuffle(Linkedlist &list1, int percent)
	{
		// Check percent.
		if(percent <0 && percent >100)
		{
			cout << "percent <0 or >100 ." << endl;
		}
		else
		{
			// Convert percent in one digit.
			int per = (list1.numOfValue()*percent)/100 ;
			if((list1.numOfValue()*percent)%100 >= 50)
			{
				per++;
			}
			cout << "Cut " << per << "  and backshuffle." << endl;
			
			int num = list1.numOfValue();
			int longJump = 1;
			int adjust = num-per;
			int continue_link;
			if(per>=adjust)
			{
				adjust = per;
			}

			// percent more than 50%.
			// create continue_link. 
			if(per>=5)
			{
				continue_link = (adjust*2) - num;
			}
			else
			{
				continue_link = (adjust*2) - num-1;
			}
			cout << "continue_link is  ==>  " << continue_link << endl;
			// Create step1 & step2.
			int step1 = (num-longJump-continue_link-1)/2;
			int step2 = (num-longJump-continue_link-1)/2;
			if((num-longJump-continue_link-1)%2 != 0)
			{
				step1++;
			}
			cout << "step1 is  ==> " << step1 <<endl;
			cout << "step2 is  ==> " << step2 <<endl;

			//back shuffle
			Cell *before = start->link;
			Cell *ptjump = before->link;
			Cell *after = start->link;
			Cell *before2 = ptjump;
			Cell *after2 =  ptjump;
			cout << "data =>   " << after->data << endl;
			cout << "data2 =>   " << after2->data << endl;
			int count1 = 0, count2 = 0;
			//run step1 & step2
			while(step2 != count1)
			{
				after = (after->link)->link;
				after2 =(after2->link)->link;
				before->link = after;
				cout << "data =>   " << after->data << endl;
				count1++;
				before2->link = after2;
				count2++;
				cout << "data2 =>   " << after2->data << endl;
				before = after;
				before2 = after2;
			}
			//Check if step1>step2 run step1 again.
			if(step1>step2)
			{
			after = (after->link)->link;
			before->link = after;
			cout << "data =>   " << after->data << endl;
			count1++;
			before = after;
			}
	
			//If per >=5 step1->longJump , step2->continue_link , last-continue_link == NULL...
			//If per<5 step1->continue_link ->longJump, last-step2->NULL...
			if(per>=5)
			{
				before->link = ptjump;
				for(int i =0; i<continue_link;i++)
				{
					before2 = before2->link;
				}
				before2->link = nullptr;
			}
			else
			{
				for(int i =0 ; i<continue_link;i++)
				{
				before = before->link;		
				}
				before->link = ptjump;
				before = ptjump;		
				before2->link = nullptr;
				cursor = before2;
			}
		}
	}
	
int main()
{
	Linkedlist <char> list;
	list.createCell('1');
	list.createCell('2');
	list.createCell('3');
	list.createCell('4');
	list.createCell('5');
	list.createCell('6');
	list.createCell('7');
	list.createCell('8');
	list.createCell('9');
	list.createCell('0');
	
	list.showAllValue();
	int percent, percent2;
	cout << "input rotate" << endl;
	cin >> percent;
	cout << "input shuffle" << endl;
	cin >> percent2;
	cout << "======== Cut Cell ============" << endl;
	list.cutCell(list,percent);
	
	cout << "********* Show Cell ************" << endl;
	list.showAllValue();
	
	cout << "======== Shuffle Cell ============" << endl;
	list.shuffle(list,percent2);
	
	cout << "********* Show Cell ************" << endl;
	list.showAllValue();
	
	cout << "======== Shuffle Cell again ============" << endl;
	list.backShuffle(list,99-percent2);

	cout << "********* Show Cell ************" << endl;
	list.showAllValue();
	
	cout << "======== Cut Cell ============" << endl;
	list.cutCell(list,99-percent);
	
	
	cout << "********* Show Cell ************" << endl;
	list.showAllValue();

	return 0;
}