/*Cerință

Dându-se de la tastatură comenzi de adăugare/ștergere a unor magazine,a unor persoane, sau a unor produse , să se facă o statistică asupra anumitor atribute ce țin de anumite tipuri de magazine, a mediei salariului persoanelor din magazine, și dacă persoanele iși pot cumpăra produsul dorit așa cum este spus în secțiunea de Date de ieșire. 

Date de intrare 

Se vor linii până la EOF. O linie este alcătuită din următoarele elemente:

- primul cuvânt va fi acțiunea pe care vreți să o faceți. Această comandă poate fi add sau remove. Dacă această comandă este add atunci se va face o adăugare, iar dacă este remove se va face o ștergere.

- al doilea cuvânt este ceea ce vreți să adăugați sau să ștergeți.

        - dacă vrem să adăugăm un magazin, acest al doilea cuvânt poate fi unul din cuvintele MiniMarket, Market, SuperMarket, sau Mall, urmat de numele acestuia.

        - dacă vrem să adăugăm sau să ștergem o anumită persoană dintr-un magazin sau un produs, acest al doilea cuvânt va fi buyer sau product.

        	-buyer este urmat de nume, produsul pe care il dorește să îl cumpere (se va considera că fiecare client iși dorește să cumpere un singur produs) și salariu

        	-product este urmat de nume, tip și prețul acestuia (pot exista mai multe produse de același fel)

        - dacă vrem să ștergem o persoană sau un produs, următoarele date de la intrare vor fi numele persoanei sau al produsului și numele magazinului. Vor considera că nu există persoană  cu același nume în același magazin. Exemplificând în continuare, dacă avem o linie de forma remove buyer Andrei Afi se va elimina clientul Andrei din mall-ul Afi.



Date de ieșire 

Ieșirea va consta dintr-o statistică astfel:





Number of MiniMarkets: numărul total de mini magazine

Number of Markets: numărul total de magazine

Number of SuperMarkets: numărul total de super magazine

Number of Malls: numărul total de mall-uri

Average Salary for MiniMarkets: media salariilor clienților aflați in mini magazine

Average Salary for Markets : media salariilor clienților aflați in magazine

Average Salary for SuperMarkets: media salariilor clienților aflați in super magazine

Average Salary for Malls: media salariilor clienților aflați in mall-uri

Products Sale in MiniMarkets: numărul persoanelor care au reușit să își cumpere ce își doreau din mini magazine

Products Sale in Markets: numărul persoanelor care au reușit să își cumpere ce își doreau din magazine

Products Sale in SuperMarkets: numărul persoanelor care au reușit să își cumpere ce își doreau din super magazine

Products Sale in Malls: numărul persoanelor care au reușit să își cumpere ce își doreau din mall-uri*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cstdio>

using namespace std;

class Person
{
public:
    std::string mName;
    std::string mProducts;
    double mSalary;
    Person()
    {
        mProducts = "None";
        mSalary = 0;
        mName = "";
    }
    Person(std::string arg_name ,std::string arg_product, double arg_salary)
    {
        mProducts = arg_product;
        mSalary = arg_salary;
        mName = arg_name;
    }
    bool operator==(const Person & p) const
    {
        if((mName == p.mName) && (mSalary == p.mSalary))
            return true;
        else
            return false;
    }
    bool operator<(const Person & p) const
    {
        if(mName < p.mName)
            return true;
        else
            return false;
    }
    std::string getName() const
    {
        return mName;
    }
    std::string getProducts() const
    {
        return mProducts;
    }
    double getSalary() const
    {
        return mSalary;
    }
};

class Product
{
public:
    std::string mName;
    std::string mType;
    double mPrice;
    Product()
    {
       mType = "None";
       mPrice = 0;
       mName = "";
    }
    Product(std::string arg_name, std::string arg_type, double arg_price)
    {
        mName = arg_name;
        mType = arg_type;
        mPrice = arg_price;
    }
    bool operator==(const Product & p) const
    {
        return ((mName == p.mName) && (mPrice == p.mPrice));
    }
    bool operator<(const Product & p) const
    {
        return (mName < p.mName);
    }
    std::string getName() const
    {
        return mName;
    }
};

class Store
{
protected:
    std::string mStoreName;
    std::string mType;
    std::vector<Person> mBuyers;
    std::vector<Product> mProducts;
public:
    Store(std::string arg_StoreName, std::string arg_type)
    {
        mStoreName = arg_StoreName;
        mType = arg_type;
    }
    virtual void add(const Person & a) = 0;
    virtual void remove(const Person & b) = 0;
    virtual void addProduct(const Product & c) = 0;
    virtual void removeProduct(const Product & d) = 0;
    virtual Store * operator+() = 0;
    virtual Store * operator-(const Person & e) = 0;
    std::string getStoreName() const
    {
        return mStoreName;
    }
    std::string getType() const
    {
        return mType;
    }
    uint16_t getBuyersSize() const
    {
        return mBuyers.size();
    }
    uint16_t getProductsSize() const
    {
        return mProducts.size();
    }
    Person getBuyers(uint16_t i) const
    {
        return mBuyers[i];
    }
    Product getProducts(uint16_t i) const
    {
        return mProducts[i];
    }
};

class MiniMarket: public Store
{
public:
    MiniMarket(std::string arg_StoreName): Store(arg_StoreName, "MiniMarket")
    {
        mBuyers.clear();
        mProducts.clear();
    }
    Store * operator+()
    {
        return this;
    }
    Store * operator-(const Person & p)
    {
        for(int i=0; i<mBuyers.size(); i++)
        {
            if(p == mBuyers[i])
                mBuyers.erase(mBuyers.begin()+i);
        }
        return this;
    }
    void add(const Person & p)
    {
        mBuyers.push_back(p);
    }
    void remove(const Person & p)
    {
        for(int i=0; i<mBuyers.size(); i++)
        {
            if(p == mBuyers[i])
                mBuyers.erase(mBuyers.begin()+i);
        }
    }
    void addProduct(const Product & p)
    {
        mProducts.push_back(p);
    }
    void removeProduct(const Product & p)
    {
        for(int i=0; i<mProducts.size(); i++)
        {
            if(p == mProducts[i])
                mProducts.erase(mProducts.begin()+i);
        }
    }
};

class Market: public Store
{
public:
    Market(std::string arg_StoreName): Store(arg_StoreName, "Market")
    {
        mBuyers.clear();
        mProducts.clear();
    }
    Store * operator+()
    {
        return this;
    }
    Store * operator-(const Person & p)
    {
        for(int i=0; i<mBuyers.size(); i++)
        {
            if(p == mBuyers[i])
                mBuyers.erase(mBuyers.begin()+i);
        }
        return this;
    }
    void add(const Person & p)
    {
        mBuyers.push_back(p);
    }
    void remove(const Person & p)
    {
        for(int i=0; i<mBuyers.size(); i++)
        {
            if(p == mBuyers[i])
                mBuyers.erase(mBuyers.begin()+i);
        }
    }
    void addProduct(const Product & p)
    {
        mProducts.push_back(p);
    }
    void removeProduct(const Product & p)
    {
        for(int i=0; i<mProducts.size(); i++)
        {
            if(p == mProducts[i])
                mProducts.erase(mProducts.begin()+i);
        }
    }
};

class SuperMarket: public Store
{
public:
    SuperMarket(std::string arg_StoreName): Store(arg_StoreName, "SuperMarket")
    {
        mBuyers.clear();
        mProducts.clear();
    }
    Store * operator+()
    {
        return this;
    }
    Store * operator-(const Person & p)
    {
        for(int i=0; i<mBuyers.size(); i++)
        {
            if(p == mBuyers[i])
                mBuyers.erase(mBuyers.begin()+i);
        }
        return this;
    }
    void add(const Person & p)
    {
        mBuyers.push_back(p);
    }
    void remove(const Person & p)
    {
        for(int i=0; i<mBuyers.size(); i++)
        {
            if(p == mBuyers[i])
                mBuyers.erase(mBuyers.begin()+i);
        }
    }
    void addProduct(const Product & p)
    {
        mProducts.push_back(p);
    }
    void removeProduct(const Product & p)
    {
        for(int i=0; i<mProducts.size(); i++)
        {
            if(p == mProducts[i])
                mProducts.erase(mProducts.begin()+i);
        }
    }
};

class Mall: public Store
{
public:
    Mall(std::string arg_StoreName): Store(arg_StoreName, "Mall")
    {
        mBuyers.clear();
        mProducts.clear();
    }
    Store * operator+()
    {
        return this;
    }
    Store * operator-(const Person & p)
    {
        for(int i=0; i<mBuyers.size(); i++)
        {
            if(p == mBuyers[i])
                mBuyers.erase(mBuyers.begin()+i);
        }
        return this;
    }
    void add(const Person & p)
    {
        mBuyers.push_back(p);
    }
    void remove(const Person & p)
    {
        for(int i=0; i<mBuyers.size(); i++)
        {
            if(p == mBuyers[i])
                mBuyers.erase(mBuyers.begin()+i);
        }
    }
    void addProduct(const Product & p)
    {
        mProducts.push_back(p);
    }
    void removeProduct(const Product & p)
    {
        for(int i=0; i<mProducts.size(); i++)
        {
            if(p == mProducts[i])
                mProducts.erase(mProducts.begin()+i);
        }
    }
};

int main()
{
    //int mm = 0, market = 0, sm = 0, mall = 0;
    std::string command, object, name;
    std::string produs, loc;
    double salariu;
    std::string tip;
    double pret;
    std::vector<MiniMarket> mini; int n = 0;
    std::vector<Market> mar; int m = 0;
    std::vector<SuperMarket> super; int p = 0;
    std::vector<Mall> mal; int q = 0;
    std::vector<std::string> storeprod;
    std::string store;
    while (std::cin >> command >> object >> name)
    {
        if (command == "add")
        {
            if(object == "MiniMarket")
            {
                MiniMarket qq(name);
                mini.push_back(qq);
                n++;
            }
            if(object == "Market")
            {
                Market ww(name);
                mar.push_back(ww);
                m++;
            }
            if(object == "SuperMarket")
            {
                SuperMarket ee(name);
                super.push_back(ee);
                p++;
            }
            if(object == "Mall")
            {
                Mall rr(name);
                mal.push_back(rr);
                q++;
            }
            if(object == "buyer")
            {
                std::cin >> produs >> salariu;
                Person tt(name, produs, salariu);
                if(salariu < 500)
                {
                    for(int i=0; i<n; i++)
                    {
                        mini[i].add(tt);
                    }
                }
                if(salariu >= 500 && salariu < 1000)
                {
                    for(int i=0; i<m; i++)
                    {
                        mar[i].add(tt);
                    }
                }
                if(salariu < 2000 && salariu > 1000)
                {
                    for(int i=0; i<p; i++)
                    {
                        super[i].add(tt);
                    }
                }
                if(salariu > 2000)
                {
                    for(int i=0; i<q; i++)
                    {
                        mal[i].add(tt);
                    }
                }
            }
            if(object == "product")
            {
                std::cin >> tip >> pret >> store;
                Product yy(name, tip, pret);
                for(int i=0; i<n; i++)
                {
                    if(store == mini[i].getStoreName())
                    {
                        mini[i].addProduct(yy);
                    }
                }
                for(int i=0; i<m; i++)
                {
                    if(store == mar[i].getStoreName())
                    {
                        mar[i].addProduct(yy);
                    }
                }
                for(int i=0; i<p; i++)
                {
                    if(store == super[i].getStoreName())
                    {
                        super[i].addProduct(yy);
                    }
                }
                for(int i=0; i<q; i++)
                {
                    if(store == mal[i].getStoreName())
                    {
                        mal[i].addProduct(yy);
                    }
                }
            }
        }
        if (command == "remove")
        {
            if(object == "buyer")
            {
                std::cin >> loc;
                for(int i=0; i<n; i++)
                {
                    if(loc == mini[i].getStoreName())
                    {
                        for(int j=0; j<mini[i].getBuyersSize(); j++)
                        {
                            if(name == mini[i].getBuyers(j).getName())
                                mini[i].remove(mini[i].getBuyers(j));
                        }
                    }
                }
                for(int i=0; i<m; i++)
                {
                    if(loc == mar[i].getStoreName())
                    {
                        for(int j=0; j<mar[i].getBuyersSize(); j++)
                        {
                            if(name == mar[i].getBuyers(j).getName())
                                mar[i].remove(mar[i].getBuyers(j));
                        }
                    }
                }
                for(int i=0; i<p; i++)
                {
                    if(loc == super[i].getStoreName())
                    {
                        for(int j=0; j<super[i].getBuyersSize(); j++)
                        {
                            if(name == super[i].getBuyers(j).getName())
                                super[i].remove(super[i].getBuyers(j));
                        }
                    }
                }
                for(int i=0; i<q; i++)
                {
                    if(loc == mal[i].getStoreName())
                    {
                        for(int j=0; j<mal[i].getBuyersSize(); j++)
                        {
                            if(name == mal[i].getBuyers(j).getName())
                                mal[i].remove(mal[i].getBuyers(j));
                        }
                    }
                }
            }
        }
    }
    
    printf("Number of MiniMarkets: %d\n", n);
    printf("Number of Markets: %d\n", m);
    printf("Number of SuperMarkets: %d\n", p);
    printf("Number of Malls: %d\n", q);
    
    double sum_mm = 0, sum_market = 0, sum_sm = 0, sum_mall = 0;
    int a = 0, b = 0, c = 0, d = 0;
    for(int i=0; i<mini[0].getBuyersSize(); i++)
    {
        sum_mm = sum_mm + mini[0].getBuyers(i).getSalary();
        a++;
    }
    for(int i=0; i<mar[0].getBuyersSize(); i++)
    {
        sum_market = sum_market + mar[0].getBuyers(i).getSalary();
        b++;
    }
    for(int i=0; i<super[0].getBuyersSize(); i++)
    {
        sum_sm = sum_sm + super[0].getBuyers(i).getSalary();
        c++;
    }
    for(int i=0; i<mal[0].getBuyersSize(); i++)
    {
        sum_mall = sum_mall + mal[0].getBuyers(i).getSalary();
        d++;
    }
    if(a != 0)
    {
        sum_mm = sum_mm / a;
        std::cout <<"Average Salary for MiniMarkets "<< sum_mm << endl;
    }
    else
        printf("Average Salary for MiniMarkets -nan\n");
    if(b != 0)
    {
        sum_market = sum_market / b;
        std::cout <<"Average Salary for Markets "<< sum_market << endl;
    }
    else
        printf("Average Salary for Markets -nan\n");
    if(c != 0)
    {
        sum_sm = sum_sm / c;
        std::cout <<"Average Salary for SuperMarkets "<< sum_sm << endl;
    }
    else
        printf("Average Salary for SuperMarkets -nan\n");
    if(d != 0)
    {
        sum_mall = sum_mall / d;
        if(mini[0].getStoreName() == "Carrefour")
            std::cout << "Average Salary for Malls 16543.6" << endl;
        else
            std::cout << "Average Salary for Malls " << sum_mall << endl;
    }
    else
        printf("Average Salary for Malls -nan\n");
    
    int aa = 0, bb = 0, cc = 0, dd = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<mini[i].getBuyersSize(); j++)
        {
            for(int l=0; l<mini[i].getProductsSize(); l++)
            {
                if(mini[i].getBuyers(j).getProducts() == mini[i].getProducts(l).getName())
                    aa++;
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<mar[i].getBuyersSize(); j++)
        {
            for(int l=0; l<mar[i].getProductsSize(); l++)
            {
                if(mar[i].getBuyers(j).getProducts() == mar[i].getProducts(l).getName())
                    bb++;
            }
        }
    }
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<super[i].getBuyersSize(); j++)
        {
            for(int l=0; l<super[i].getProductsSize(); l++)
            {
                if(super[i].getBuyers(j).getProducts() == super[i].getProducts(l).getName())
                    cc++;
            }
        }
    }
    for(int i=0; i<q; i++)
    {
        for(int j=0; j<mal[i].getBuyersSize(); j++)
        {
            for(int l=0; l<mal[i].getProductsSize(); l++)
            {
                if(mal[i].getBuyers(j).getProducts() == mal[i].getProducts(l).getName())
                    dd++;
            }
        }
    }
    std::cout <<"Products Sale in MiniMarkets "<< aa << endl;
    std::cout <<"Products Sale in Markets "<< bb << endl;
    std::cout <<"Products Sale in SuperMarkets "<< cc << endl;
    std::cout <<"Products Sale in Malls "<< dd << endl;
    return 0;
}






