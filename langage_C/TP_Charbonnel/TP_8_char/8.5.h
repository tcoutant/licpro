struct person
{
	char firstname[20], lastname[20] ;
	int age ;
} ;

struct FrAddress
{
	int numero ;
	char rue[20] ;
	int postal_code  ;
	char ville[10] ;
} ;

struct USAddress
{
  int house_number ;
  char street[20], direction[5] ;
  char locality[20], province[12], postal_code[8] ;
} ;

struct UKAddress
{
  int house_number ;
  char street[15] ;
  char town[10], region[12], postal_code[8] ;
} ;

union Address
{
	struct UKAddress ukaddr ;
	struct FrAddress fraddr ;
	struct USAddress usaddr ;
} ;

enum country { fr, uk, us } ;

struct contact {
 struct person this_person ;
 enum country his_country ;
 union Address his_address ;
} ;

