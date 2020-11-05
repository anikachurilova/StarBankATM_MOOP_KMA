#include <iostream>
#include <map>
using namespace std;

class ATM;
class CashDispencer
{
private:
	bool _blocked=false;
	static const int _MIN_AMOUNT=50;
	int _totalCashAmount;
	map<int,int> _notesMap;
    map<int,int> _notesOutMap;
	ATM& _atm;
	CashDispencer(const CashDispencer&);
	CashDispencer& operator=
		(const CashDispencer&);

public:
    class BadAmount;
	CashDispencer(ATM&);
	~CashDispencer();
	bool isBlocked(){return _blocked;} // if is blocked - we cant withdraw money
    void initialiseNotes();
    bool has50(int x = 0)  { return _notesMap[50] - x > 0; }
    bool has100(int x = 0)  { return _notesMap[100] - x > 0; }
    bool has200(int x = 0)  { return _notesMap[200] - x > 0; }
    bool has500(int x = 0)  { return _notesMap[500] - x > 0; }
	bool isCorrectAmount(int) ;
	int getTotalCashAmount() const {return _totalCashAmount;}
	void setTotalCashAmount();
    const map<int, int> calculateNotesOut(const int);
    void updateNotesMap(map<int,int>);
    const map<int, int> getNotesOut(const int);
};

class CashDispencer::BadAmount
{
private:
    const string _reason;
    const int _number;

public:
    BadAmount(string reason, const int num)
            :_reason(reason), _number(num)
    {
        return;
    }

    ~BadAmount() { }

    void diagnose() const{
        cerr << _reason << endl;
        cerr << ' ' << _number << endl;
    }
};
ostream& operator<<(ostream&, CashDispencer&);

