#include <cstdio>

int gcd(int a, int b) {
  while (b != a) {
    if (a < b)
      b -= a;
    else
      a -= b;
  }
  return a;
}

/* Hier die Klasse RationalNumber implementieren! */
class RationalNumber{
  private:
   int numerator_; // der Zähler
   int denominator_; // der Nenner

    void reduce(){
     int GCD = gcd(numerator_, denominator_);
     numerator_ = numerator_ / GCD;
     denominator_ = denominator_ / GCD;
    }
  public:
   RationalNumber(): numerator_(0), denominator_(0){}
   RationalNumber(int numerator_): numerator_(numerator_), denominator_(1){}
   RationalNumber(int numerator_, int denominator_): numerator_(numerator_), denominator_(denominator_){}

   RationalNumber invert() const{
    return RationalNumber(denominator_, numerator_);
   }

   float to_float() const{ 
    float toFloat = numerator_ / (denominator_ * 1.0);
    return toFloat;
   }

   void add(const RationalNumber& other){
    numerator_ = (numerator_ * other.denominator_) + denominator_ * other.numerator_;
    denominator_ = denominator_ * other.denominator_;
    reduce();
   }

   void sub(const RationalNumber& other){
    numerator_ = (numerator_ * other.denominator_) - denominator_ * other.numerator_;
    denominator_ = denominator_ * other.denominator_;
    reduce();
   }

   void mul(const RationalNumber& other){
    numerator_ = numerator_ * other.numerator_;
    denominator_ = denominator_ * other.denominator_;
    reduce();
   }

   void div(const RationalNumber& other){
    numerator_ = numerator_ * other.denominator_;
    denominator_ = denominator_ * other.numerator_;
    reduce();
   }
};

int main() {
  RationalNumber number(7, 2);
  printf("%g\n", number.to_float());  // Ausgabe: 3.5

  RationalNumber number2(8, 2);
  RationalNumber inverted = number2.invert();
  printf("%g\n", inverted.to_float());  // Ausgabe: 0.25

  RationalNumber threeEigth(3, 8);
  RationalNumber oneQuarter(1, 4);
  oneQuarter.add(threeEigth);
  printf("%g\n", oneQuarter.to_float());  // Ausgabe: 0.625
  printf("%g\n", threeEigth.to_float());  // Ausgabe: 0.375

  RationalNumber const fixedNumber(40, 8);
  printf("%g\n", fixedNumber.to_float());  // Ausgabe: 5
  RationalNumber inverted2 = fixedNumber.invert();
  printf("%g\n", inverted2.to_float());  // Ausgabe: 0.2

  // Die folgenden Zeilen sollten zu Fehlern führen:
  // number.reduce();
  // printf("%g\n", number.numerator_);
  // printf("%g\n", number.denominator_);
  // fixedNumber.add(number);
  // fixedNumber.sub(number);
  // fixedNumber.mul(number);
  // fixedNumber.div(number);
}