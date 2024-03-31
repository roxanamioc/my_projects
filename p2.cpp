/*O firmă v-a cerut ajutorul pentru a crea un demo al unei aplicații de Blackjack. Blackjack este unul dintre cele mai ușoare jocuri de înțeles cu cărți, regulile fiind următoarele:

Cărțile de la 2 la 10 au valoarea inscripționată pe ele, în timp ce figurile (J,Q,K) au valoarea 10, iar asul (A) poate avea valoarea 1 sau 11.
Jucătorii joacă împotriva unei persoane care este denumită Dealer și pentru a câștiga ei trebuie să aibă suma cărților mai mare decât cea a dealer-ului. Dacă suma cărților depășește valoarea 21 jucătorul respectiv pierde. Dacă dealer-ul depășește valoarea 21, atunci toată lumea prezentă la masă câștigă, cu excepția celor care au depășit 21 înaintea dealer-ului.
Fiecare jucător primește la început 2 cărți, iar dealer-ul primește tot 2 cărți, dar una este întoarsă (ATENTIE! În jocul real de Blackjack cărțile sunt date câte una la fiecare jucător și abia după și a doua la fiecare jucător, dar pentru a simplifica problema, vom considera că jucătorii primesc cele 2 cărți din prima, iar dealer-ul este ultima persoană care primește cele 2 cărți).
După ce cărțile au fost împărțite, fiecare jucător are dreptul de a trage o carte (HIT) sau de a se opri la suma pe care o are deja (STAND). Jucătorii pot trage orice câte cărți vor, dar dacă au depășit 21 au pierdut (ATENTIE! Pentru simplitate vom considera următorul scenariu: Dacă suma cărților dealer-ului sau a jucătorilor este mai mică decât 16, ei sunt obligați să tragă o carte. Dacă suma cărților este 17-21 ei trebuie să se oprească din a trage cărți. Dacă suma este mai mare ca 21 au pierdut).

Cerințe funcționale
1) Dacă command este "check_cards", să se verifice dacă un pachet de cărți este măsluit, dacă este un pachet normal sau dacă este un pachet pregătit pentru blackjack. Un pachet de cărți se consideră măsluit dacă există cărți ale căror numere sau steme nu există în realitate (numerele permise sunt cele de la 2 la 14, unde 11 este asul, iar stemele permise sunt rosu, negru, romb sau trefla) și se va afișa "Pachet măsluit". Un pachet de cărți este considerat OK dacă nu este măsluit, dacă toate cărțile din el sunt diferite și dacă în total sunt 52 de cărți, iar în acest caz se va afișa "Pachet OK". Un pachet este considerat bun pentru Blackjack dacă nu este măsluit, iar în acest caz se va afișa "Pregatit pentru Blackjack". Se va lăsa un newline (\n) după aceste printări.

2) Dacă command este "shuffle_cards", să se amestece cărțile folosind algoritmul Linear Congruential Generator (LCG). Generatorul este definit prin relația de recurență Xn+1 = (a * Xn + c) mod m. Dacă sunt date de la tastatură 2 perechi de numere a, c și X0, atunci se va genera o pereche de indecși și cărțile de pe pozițiile respective se vor interschimba, iar indexul curent va deveni index anterior pentru generator (Vezi exemplu!). Constanta m va reprezenta numărul de cărți din pachet. Acest algoritm va fi aplicat pachetului de 50 de ori. Se vor afișa cărțile din pachet amestecate în formatul <numar_carte>,<stema_carte>, separate prin newline (\n).

3) Dacă command este "play_game", să se joace jocuri de Blackjack până la EOF cu n jucători la o masă. Jocul se va desfăşura după regulile enunţate la începutul problemei. Se consideră că în pachet NU EXISTĂ ași! (Adică pachetul va fi format din 48 de cărți, nu 52!) Se va consulta exemplul pentru o înţelegere clară a problemei. Pachetul de cărți va fi amestecat la fiecare rundă de Blackjack folosind algoritmul LCG descris mai sus (aplicat tot de 50 de ori). Inițial pachetul de cărți este aranjat în ordinea următoare: vor exista 48 de cărți într-un pachet (deoarece nu avem ași) în ordinea 2 rosu, 3 rosu, ..., 14 rosu, 2 negru, ..., 14 negru, 2 romb, ..., 14 romb, 2 trefla, ..., 14 trefla (Atenție că nu există 11!). La fiecare rundă pachetul de cărți va fi amestecat folosind algoritmul LCG cu valorile curente citire de la tastatură. Miza este de 10 euro per jucător astfel că câștigul rundei aduce jucătorului 10 euro, iar dacă pierde va avea 10 euro pe minus. Dacă jucătorul rămâne fără bani (are sub 10 euro) acesta va părăsi masa. La final, se vor afișa persoanele rămase la masă în formatul nume_persoana: suma_bani, separate prin newline (\n).

Date de intrare
Pe prima linie se află un cuvânt command, reprezentând subpunctul pe care vreţi să îl faceţi. Pentru subpunctul 1), se citesc de la tastatură, până la EOF, linii de norma <numar_carte>,<stema_carte>, unde numar_carte este un număr întreg, fără semm, pe 8 biți, iar stema_carte este un șir de caractere de maximum 30 de caractere. Pentru subpunctul 2), se citesc de la tastatură 6 numere întregi, 3 pe o linie și 3 pe alta, reprezentând constantele a, c și X0. Apoi, se citesc cărți până la EOF în formatul specificat la subpunctul punctul 1). Pentru subpunctul 3), se citeşte un număr întreg n care reprezintă numărul de jucători prezenţi la masa de Blackjack. Pe următoarele n linii se găsesc cei n jucători în formatul <nume> <suma_bani>, unde nume este un şir de caractere ce reprezintă numele jucătorului, format dintr-un singur cuvânt, iar suma_bani reprezintă suma de bani cu care intră acesta la masă, număr întreg fără semn pe 32 de biți. Pe următoarele linii până la EOF se citesc câte 6 valori pe linie, reprezentând intrările generatorului LCG pentru amestecarea cărților din jocul curent.

Date de ieşire
Valorile se vor afișa la ieșire conform specificației din cerință, fără a afişa altfel de text suplimentar în consolă! Afişaţi doar rezultatul cerut!


Restricții și precizări
1 <= n <= 20;
nume și stema_carte au maxim 30 de caractere.
suma_bani este un număr întreg pe 16 biți.
NU se acceptă soluţii hardcodate!
In caz de remiza jucatorul nici nu pierde, nici nu castiga bani.
Dealer-ul primeste cartile ultimul.
Intai toti jucatorii primesc 2 carti (+dealer) apoi se trece in etapa de hit/stand.
Pachetul se imparte de la pozitia 0, apoi 1, apoi 2.
Intre runde pachetul se reamestecă pornind de la configuratia rundei anterioare. */

//////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cstdio>

using namespace std;

class LcgGenerator
{
private:
    uint16_t mA;
    uint16_t mC;
    uint16_t mCurrentX;
    uint16_t mM;
public:
    LcgGenerator(uint16_t arg_a, uint16_t arg_c, uint16_t arg_currentX, uint16_t arg_m)
    {
        mA = arg_a;
        mC = arg_c;
        mCurrentX = arg_currentX;
        mM = arg_m;
    }
    uint16_t next()
    {
        mCurrentX = (mA * mCurrentX + mC) % mM;
        return mCurrentX;
    }
};

class Card
{
private:
    std::string mSuite;
    uint16_t mValue;
public:
    Card(const std::string & arg_suite, uint16_t arg_value)
    {
        mSuite = arg_suite;
        mValue = arg_value;
    }
    bool operator==(const Card & c) const
    {
        return ((mSuite == c.mSuite) && (mValue == c.mValue));
    }
    std::string toString() const
    {
        return to_string(mValue) + "," + mSuite;
    }
    bool isFake() const
    {
        return ((mSuite != "negru" && mSuite != "rosu" && mSuite != "romb" && mSuite != "trefla") || (mValue < 2 || mValue > 14));
    }
    uint16_t getBlackjackValue() const
    {
        if(mValue >= 2 && mValue <= 9)
            return mValue;
        else
            return 10;
    }
    uint16_t getValue() const
    {
        return mValue;
    }
    Card egal(Card c)
    {
        this->mSuite = c.mSuite;
        this->mValue = c.mValue;
        return *this;
    }
};

class CardPack
{
private:
    std::vector<Card> mCards;
    uint16_t mCurrentIndex;
public:
    CardPack(bool empty)
    {
        if(empty == true)
        {
            mCurrentIndex = 0;
        }
        else
        {
            mCurrentIndex = 0;
            for(int i=2; i<=10; i++)
                mCards.push_back(Card("rosu", i));
            for(int i=12; i<=14; i++)
                mCards.push_back(Card("rosu", i));
            for(int i=2; i<=10; i++)
                mCards.push_back(Card("negru", i));
            for(int i=12; i<=14; i++)
                mCards.push_back(Card("negru", i));
            for(int i=2; i<=10; i++)
                mCards.push_back(Card("romb", i));
            for(int i=12; i<=14; i++)
                mCards.push_back(Card("romb", i));
            for(int i=2; i<=10; i++)
                mCards.push_back(Card("trefla", i));
            for(int i=12; i<=14; i++)
                mCards.push_back(Card("trefla", i));
        }
    }
    bool goodForBackjack() const
    {
        for(int i=0; i<52; i++)
        {
            if(mCards[i].isFake() == 0)
                return true;
            else
                return false;
        }
    }
    bool ok() const
    {
        if(mCards.size() == 52)
        {
            for(int i=0; i<51; i++)
            {
                for(int j=i+1; j<52; j++)
                {
                    if(mCards[i].isFake() == 0 && mCards[j].isFake() == 0)
                    {
                        if(mCards[i] == mCards[j])
                            return false;
                    }
                    else
                        return false;
                }
            }
            return true;
        }
        return false;
    }
    void addCard(const Card & c)
    {
        mCards.push_back(c);
    }
    void shuffle(uint16_t a1, uint16_t c1, uint16_t x01, uint16_t a2, uint16_t c2, uint16_t x02)
    {
        mCurrentIndex = 0;
        for(int i=0; i<50; i++)
        {
            Card c("", 0);
            x01 = (a1 * x01 + c1) % mCards.size();
            x02 = (a2 * x02 + c2) % mCards.size();
            c.egal(mCards[x01]);
            mCards[x01].egal(mCards[x02]);
            mCards[x02].egal(c);
        }
    }
    void printPack() const
    {
        for(int i=0; i<mCards.size(); i++)
        {
            cout << mCards[i].toString() << endl;
        }
    }
    Card nextCard()
    {
        mCurrentIndex++;
        return mCards[mCurrentIndex-1];
    }
    uint16_t getSizeCards() const
    {
        return mCards.size();
    }
    Card getCard(int i)
    {
        return mCards[i];
    }
};

class Player
{
private:
    std::string mName;
    uint16_t mMoney;
    uint16_t mPoints;
public:
    Player(std::string arg_name, uint16_t arg_money)
    {
        mName = arg_name;
        mMoney = arg_money;
        mPoints = 0;
    }
    std::string toString() const
    {
        return mName + ": " + to_string(mMoney);
    }
    void pick(const Card & c)
    {
        mPoints = mPoints + c.getBlackjackValue();
    }
    void play(CardPack & c)
    {
        while(mPoints < 17)
        {
            mPoints = mPoints + c.nextCard().getBlackjackValue();
        }
    }
    void newRound()
    {
        mPoints = 0;
    }
    bool lostRound() const
    {
        return mPoints > 21;
    }
    uint16_t getPoints() const
    {
        return mPoints;
    }
    void operator--()
    {
        mMoney = mMoney - 10;
    }
    void operator++()
    {
        mMoney = mMoney + 10;
    }
    bool lostGame() const
    {
        return mMoney < 10;
    }
};

int main()
{
    std::string command;
    cin >> command;
    CardPack pack(1);
    uint8_t numar_carte;
    char stema_carte[31];

    if(command == "check_cards")
    {
        int aux = 0;
        while(scanf("%hhu,%s\n", &numar_carte, stema_carte) != EOF)
        {
            Card c(stema_carte, numar_carte);
            pack.addCard(c);
        }
        for(int i=0; i<pack.getSizeCards(); i++)
        {
            if(pack.getCard(i).isFake() == 1)
            {
                cout << "Pachet masluit\n";
                aux = 1;
                break;
            }
        }
        if(aux == 0)
        {
            if(pack.ok() == 1)
                cout << "Pachet OK\n";
            else
                cout << "Pregatit pentru Blackjack\n";
        }
    }

    uint16_t aa1, aa2, cc1, cc2, xx01, xx02;
    if(command == "shuffle_cards")
    {
        scanf("%hu %hu %hu\n%hu %hu %hu", &aa1, &cc1, &xx01, &aa2, &cc2, &xx02);
        while(scanf("%hhu,%s\n", &numar_carte, stema_carte) != EOF)
        {
            Card c(stema_carte, numar_carte);
            pack.addCard(c);
        }
        pack.shuffle(aa1, cc1, xx01, aa2, cc2, xx02);
        pack.printPack();
    }

    if(command == "play_game")
    {
        int n;
        cin >> n;
        std::vector<Player> p;
        std::vector<CardPack> pack1;
        CardPack p1(0);
        for(int i=0; i<n; i++)
        {
            char name[31];
            uint16_t money;
            scanf("%s %hu\n", name, &money);
            Player pp(name, money);
            p.push_back(pp);
        }
        p.push_back(Player("Dealer", 0));

        int m = 0;
        while(scanf("%hu %hu %hu %hu %hu %hu \n", &aa1, &cc1, &xx01, &aa2, &cc2, &xx02)!=EOF)
        {
            m++;
            p1.shuffle(aa1, cc1, xx01, aa2, cc2, xx02);
            pack1.push_back(p1);
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<p.size(); j++)
            {
                p[j].pick(pack1[i].nextCard());
                p[j].pick(pack1[i].nextCard());
            }
            for(int j=0; j<p.size(); j++)
            {
                p[j].play(pack1[i]);
            }
            for(int j=0; j<p.size()-1; j++)
            {
                if(p[j].getPoints() > 21)
                    --p[j];
                else
                {
                    if(p[p.size()-1].getPoints() > 21)
                        ++p[j];
                    else
                    {
                        if(p[j].getPoints() > p[p.size()-1].getPoints())
                            ++p[j];
                        else
                        {
                            if(p[j].getPoints() < p[p.size()-1].getPoints())
                                --p[j];
                        }
                    }
                }
            }
            for(int j=0; j<p.size()-1; j++)
            {
                if(p[j].lostGame() == 1)
                {
                    p.erase(p.begin()+j);
                    j--;
                }
            }
            for(int j=0; j<p.size(); j++)
            {
                p[j].newRound();
            }
        }
        for(int j=0; j<p.size()-1; j++)
        {
            cout << p[j].toString() << endl;
        }
    }
    return 0;
}
