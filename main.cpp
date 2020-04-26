#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {

protected:

class Term {
protected:
int exponent;
int coefficient;
Term *next;
Term(int exp, int coeff, Term *n):
  exponent(exp), coefficient(coeff), next(n) {}
friend class Polynomial;

};
int size;
  
Term *first;

public:
Polynomial():first->exponent(0), first->coefficient(0), first->next(nullptr) {}
 
Polynomial(const Polynomial &p): first->exponent(0), first->coefficient(0), first->next(nullptr){
  
      for (Term *p = p.first; p != nullptr; p = p->next)
        addTerm(p->exponent, p->coefficient);
    }

~Polynomial(){
  Term *p = first;
  while (p != nullptr) {
  Term *q = p;
  p = p->next;
  delete q;
  }
 }


Polynomial & operator = (const Polynomial &p) {
  Term *p = first;
  while (p != nullptr) {
  Term *q = p;
  p = p->next;
  delete q;
  }
  first->next= nullptr;
  first->exponent = 0;
  first->coefficient = 0;
  for (Term *p = p.first; p != nullptr; p = p->next)
        addTerm(p->exponent, p->coefficient);
  
  return *this;
}

void addTerm(int expon, int coeff){
  Term *p = new Term(expon, coeff, nullptr);
  if (first->next != nullptr) first->next = p;
      else first = p;
}
double evaluate(double x){
  int result = 0;
  for ( Term *p = first; p != nullptr; p = p-> next){
    int partial = (p->coefficient) * pow(x , exponent);
    result = result + partial;
  }
  return result;
}

friend Polynomial operator+ (const Polynomial &p, const Polynomial &q){
  Polynomial c;
  Term *a = p.first, *b = q.first;
  if (a == nullptr && b == nullptr) return c;
  if (a == nullptr){
    return q;
  }
  if (b == nullptr){
    return p;
  }
  do{
    if (a->exponent == b->exponent){
      c.addTerm(a->exponent, (a->coefficient)+(b->coefficient));
      a = a->next;
      b = b->next;
    }else if(a->exponent > b->exponent){
      c.addTerm(a->exponent, a->coefficient);
      a = a->next;
    }else {
      c.addTerm(b->exponent, b->coefficient);
      b = b->next;
    }

  }while(a!=nullptr && b!=nullptr)
  return c;
}

friend Polynomial operator* (const Polynomial &p, const Polynomial &q){
 
}

friend ostream & operator << (ostream &out, const Polynomial &p){
  Term *a ;
  if (a->coefficient > 0){
     out<< a->coefficient<<"x^"<<a->exponent<<" ";
     a =a->next;
  }
  if (a->coefficient < 0) {
    out<<"- "<<a->coefficient<<"x^"<<a->exponent<<" ";
  a =a->next;
  }
  
  for(a = p.first; a!=nullptr; a=a->next){
    if (a->coefficient == 0) continue;
    if (a->coefficient > 0)
    out << " "<<a->coefficient << "x^" <<a->exponent<< " ";
    if (a->coefficient < 0)
    out << " - "<<a->coefficient<<"x^"<<a->exponent<<" ";

  }
  return out;
}

};

