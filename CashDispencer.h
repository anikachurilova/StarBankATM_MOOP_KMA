
#include <iostream>
#include <map>
using namespace std;

class ATM;
class CashDispencer
{
private:
	
	static const int _MIN_AMOUNT=50;
	static const int _50_AMOUNT;
	static const int _100_AMOUNT;
	static const int _200_AMOUNT;
	static const int _500_AMOUNT;

	int _totalCashAmount;

	ATM& _atm;
	CashDispencer(const CashDispencer&);
	CashDispencer& operator=
		(const CashDispencer&);

public:
	CashDispencer(ATM&);
	~CashDispencer();

	bool isCorrectAmount(int) const;

	void checkCash(int);
	map<Notes, int> incash(int _50 = 1000, int _100 = 1000, int _200 = 400,
		int _500 = 500);
	map<Notes, int> outcash(int amountToDispense);

	int getTotalCashAmount() const {return _totalCashAmount;}
};

ostream& operator<<(ostream&, CashDispencer&);

