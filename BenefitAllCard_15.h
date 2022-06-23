
#include "card.h"
class BenefitAllCard_15 :
	public Card
{
	int n_turns;
public:
	BenefitAllCard_15(const CellPosition &pos);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream &OutFile, int type);
	void OpenSaved(ifstream &Infile);

	void Setn_turns(int);

	~BenefitAllCard_15(void);
};
