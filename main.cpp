#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {

protected:

class Term {

int exponent;
int coefficient;
Term *next;
Term(int exp, int coeff, Term *n):
  exponent(exp), coefficient(coeff), next(n) {}

~Term() { delete next; }

		friend class Polynomial;

		friend ostream;

};
int size;
  
Term *first;

public:
Polynomial(){
  first=nullptr;
  first->next=nullptr;
} 
 
Polynomial(const Polynomial &p){
  Term *q = p.first;
		first = nullptr;
		while (q != nullptr) {
			this->addTerm(q->exponent, q->coefficient);
			q = q->next;
		}
}

~Polynomial(){
  delete first;
 }


Polynomial & operator = (const Polynomial &p) {
  delete first;
  Term *q = p.first;
	first = nullptr;
	while (q != nullptr) {
		this->addTerm(q->exponent, q->coefficient);
		q = q->next;
    }
  
  return *this;
}

void addTerm(int expon, int coeff){
  Term *p = new Term(expon, coeff, nullptr);
  if (first->next != nullptr) first->next = p;
      else first = p;
}
double evaluate(double x){
  double result = 0;
  for ( Term *p = first; p != nullptr; p = p-> next){
    double part = (p->coefficient) * pow(x , p->exponent);
    result = result + part;
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
 Polynomial poly;
		Term *a = p.first;
		Term *b = q.first;
		while (a != nullptr) {
			while (b != nullptr) {
				poly.addTerm(a->exponent + b->exponent,
					a->coefficient * b->coefficient);
				b = b->next;
			}
			b = q.first;
			a = a->next;
		}
		return poly;
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

