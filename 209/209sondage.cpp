#include"209sondage.hh"

sondage::sondage(char *name_, int echantillontaille)
{
  std::ifstream file;
  int tmp;

  this->name = name_;
  file.open(name_);
  file >> tmp;
  this->nbIndividus = tmp;
  file >> tmp;
  this->echantillonTaille = echantillontaille;
  while (file)
    {
      this->table.push_back(tmp);
      file >> tmp;
    }
}

sondage::~sondage()
{
}

void sondage::aff()
{
  this->Population();
  this->NbIndividus();
  this->MoyenneM();
  this->EcartTypeS();
  std::cout << std::endl;
  this->EchantillonTaille();
  this->NbEchantillon();
  this->Moyenne();
  this->EcartType();
  this->EcartTypeApresS();
}

void sondage::Population()
{
  std::cout << "Population : " << this->name << std::endl;
}

void sondage::NbIndividus()
{
  std::cout << "Nombre d'individus : " << this->nbIndividus << std::endl;
}

void sondage::MoyenneM()
{
  std::list<int>::iterator it;
  long double somme = 0;

  it = this->table.begin();
  for (; it != this->table.end(); ++it)
    somme += *it;
  this->moyM = somme / (double)this->nbIndividus;
  std::cout << "Moyenne M : " << this->moyM << std::endl;
}

void sondage::EcartTypeS()
{
  std::list<int>::iterator it;
  long double somme = 0;

  it = this->table.begin();
  for (; it != this->table.end(); ++it)
    somme += (*it - this->moyM) * (*it - this->moyM);
  this->ecartTypeS = sqrt(somme / (double)this->nbIndividus);
  std::cout << "Ecart-type s : " << this->ecartTypeS << std::endl;
}

void          sondage::EchantillonTaille()
{
  std::cout << "Echantillon de taille : " << this->echantillonTaille << std::endl;
}

double         sondage::my_fact(double n)
{
  if (n == 0)
    return (1);
  return (n * my_fact(n - 1));
}

void          sondage::NbEchantillon()
{
  long double nbEchantillons;

  nbEchantillons = this->my_fact(this->nbIndividus) / (this->my_fact(this->echantillonTaille) *  this->my_fact(this->nbIndividus - this->echantillonTaille));
  std::cout << "Nombre d'echanntillon : " << nbEchantillons << std::endl;
}

void          sondage::Moyenne()
{
  this->MoyenneM();
}

void          sondage::EcartType()
{
  long double res;

  res = sqrt(((this->ecartTypeS * this->ecartTypeS) * (this->nbIndividus - this->echantillonTaille)) / (this->echantillonTaille * (this->nbIndividus - 1)));
  std::cout << "Ecart-Type : " << res << std::endl;
}

void          sondage::EcartTypeApresS()
{
  long double res;

  res = sqrt(((this->ecartTypeS * this->ecartTypeS) * (this->nbIndividus - this->echantillonTaille)) / (this->echantillonTaille * (this->nbIndividus - 1)));
  std::cout << "Ecart-Type calcule d'apres s: " << res << std::endl;
}
