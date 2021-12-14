#include <stdio.h>
#define key         220
#define key2        252
#define SIZE        256
#define TONOS       39
#define DIALYTIKA   34
#define mikrokey    182
#define M_CAP_GR	  204
#define M_SMALL_GR	236
#define N_CAP_GR		205
#define N_SMALL_GR	237
#define P_CAP_GR		208
#define P_SMALL_GR	240
#define T_CAP_GR		212
#define T_SMALL_GR	244
#define M_CAP_EN		78
#define M_SMALL_EN	109
#define N_CAP_EN		79
#define N_SMALL_EN	110
#define B_CAP_EN		66
#define B_SMALL_EN	98
#define D_CAP_EN		68
#define D_SMALL_EN	100


enum FSM{any=0, M_cap, N_cap, m_small, n_small}state;

void filling_array(char map[SIZE][3])
{
  int i = 0,j = 0;
  char kefalaia[] = "AVGDEZH8IKLMNQOPR-STUFXYW";   /*pinakas me ola ta kefalaia grammata*/
	char mikra[] = "avgdezh8iklmnqoprsstufxyw"; /*pinakas me ola ta mikra grammata*/

  while(i<SIZE){ /*arxikopoihsh*/
    map[i][0] = i;
		map[i][1] = '\0';
		map[i][2] = '\0';
    i++;
  }

  i=225;
  while(i<250){ /*mikra*/
    map[i][0] = mikra[j];
		j++;
    i++;
  }

  j=0;
  i=193;
  while(i<218){ /*kefalaia*/
    map[i][0] = kefalaia[j];
    j++;
    i++;
  }

  /*edw ginetai h antistoixisi gia ta kefalaia me tonous*/
  map[mikrokey][0] = TONOS;
  map[mikrokey][1] = 'A';
  map[mikrokey+2][0] = TONOS;
  map[mikrokey+2][1] = 'E';
  map[mikrokey+3][0] = TONOS;
  map[mikrokey+3][1] = 'H';
  map[mikrokey+4][0] = TONOS;
  map[mikrokey+4][1] = 'I';
  map[mikrokey+6][0] = TONOS;
  map[mikrokey+6][1] = 'O';
  map[mikrokey+8][0] = TONOS;
  map[mikrokey+8][1] = 'Y';
  map[mikrokey+9][0] = TONOS;
  map[mikrokey+9][1] = 'W';

	/*edw ginetai h antistoixisi gia ta mikra me tonous*/
	map[key][0] = 'a';
	map[key][1] = TONOS;
	map[key+1][0] = 'e';
	map[key+1][1] = TONOS;
	map[key+2][0]  = 'h';
	map[key+2][1] = TONOS;
	map[key+3][0] = 'i';
	map[key+3][1] = TONOS;
	map[key2][0] = 'o';
	map[key2][1] = TONOS;
	map[key2+1][0] = 'u';
	map[key2+1][1] = TONOS;
	map[key2+2][0] = 'w';
	map[key2+2][1] = TONOS;

	/*edw ginetai h antistoixisi gia ta grammata me dialutika*/
	map[key-2][0] = 'I';
	map[key-2][1] = DIALYTIKA;
	map[key-1][0] = 'Y';
	map[key-1][1] = DIALYTIKA;
	map[key+30][0] = 'i';
	map[key+30][1] = DIALYTIKA;
	map[key+31][0] = 'u';
	map[key+31][1] = DIALYTIKA;
	map[mikrokey+10][0] = 'i';
	map[mikrokey+10][1] = TONOS;
	map[mikrokey+10][2] = DIALYTIKA;
	map[key+4][0] = 'u';
	map[key+4][1] = TONOS;
	map[key+4][2] = DIALYTIKA;

	map[key+18][0] = 'k';
	map[key+18][1] = 's'; /*ks*/

	map[key+28][0] = 'p';
	map[key+28][1] = 's'; /*ps*/

	map[key-14][0] = 'K';
	map[key-14][1] = 'S'; /*KS*/

	map[key-4][0] = 'P';
	map[key-4][1] = 'S'; /*PS*/
}

void print_it_please(int c)
{
  char map[SIZE][3];
  filling_array(map); /*gemizoume to map pou dhlwsame me thn panw sunarthsh*/
  if(map[c][0] != '\0')putchar(map[c][0]);  /*kanoume putchar opoio den einai opws arxikopoihthike-dhl alakse*/
	if(map[c][1] != '\0')putchar(map[c][1]);
	if(map[c][2] != '\0')putchar(map[c][2]);
}

/*default katastash ths fsm*/
enum FSM dflt(int c)
{
  switch (c) {
		case M_CAP_GR:
			return M_cap;
		case M_SMALL_GR:
			return m_small;
		case N_CAP_GR:
			return N_cap;
		case N_SMALL_GR:
			return n_small;
		default:
			print_it_please(c);
			return any;
	}
}

/*akolouthoun oles oi upoloipes katastaseis ths fsm*/
enum FSM M(int c)	{
  if ( c == P_CAP_GR){
		print_it_please(B_CAP_EN);
		return any;
	}
	else if ( c == P_SMALL_GR){
		print_it_please(B_CAP_EN);
		return any;
	}
	else if ( c == M_CAP_GR){
		print_it_please(M_CAP_GR);
		return M_cap;
	}
	else if ( c == M_SMALL_GR){
		print_it_please(M_CAP_GR);
		return m_small;
	}
	else if ( c == N_CAP_GR){
		print_it_please(M_CAP_GR);
		return N_cap;
	}
	else if ( c == N_SMALL_GR){
		print_it_please(M_CAP_GR);
		return n_small;
	}
	else{
		print_it_please(M_CAP_GR);
		print_it_please(c);
		return any;
	}
}


enum FSM N(int c)
{
	if ( c == T_CAP_GR){
    print_it_please(D_CAP_EN);
    return any;
	}
  else if ( c == T_SMALL_GR){
    print_it_please(D_CAP_EN);
    return any;
	}
  else if ( c == N_CAP_GR){
    print_it_please(N_CAP_GR);
    return N_cap;
	}
  else if ( c == N_SMALL_GR){
    print_it_please(N_CAP_GR);
    return n_small;
	}
  else if ( c == M_CAP_GR){
    print_it_please(N_CAP_GR);
    return M_cap;
	}
  else if ( c == M_SMALL_GR){
    print_it_please(N_CAP_GR);
    return m_small;
	}
  else{
    print_it_please(N_CAP_GR);
    print_it_please(c);
    return any;
	}
}


enum FSM m(int c)
{
	if( c == P_CAP_GR){
    print_it_please(B_SMALL_EN);
    return any;
	}
  else if ( c == P_SMALL_GR){
    print_it_please(B_SMALL_EN);
    return any;
	}
  else if ( c == M_CAP_GR){
    print_it_please(M_SMALL_GR);
    return M_cap;
	}
  else if ( c == M_SMALL_GR){
    print_it_please(M_SMALL_GR);
    return m_small;
	}
  else if ( c == N_CAP_GR){
    print_it_please(M_SMALL_GR);
    return N_cap;
	}
  else if ( c == N_SMALL_GR){
    print_it_please(M_SMALL_GR);
    return n_small;
	}
	else{
    print_it_please(M_SMALL_GR);
    print_it_please(c);
    return any;
	}
}

enum FSM n(int c)
{
	if( c == T_CAP_GR){
    print_it_please(D_SMALL_EN);
    return any;
	}
  else if ( c == T_SMALL_GR){
    print_it_please(D_SMALL_EN);
    return any;
	}
  else if ( c == M_CAP_GR){
    print_it_please(N_SMALL_GR);
    return M_cap;
	}
  else if ( c == M_SMALL_GR){
    print_it_please(N_SMALL_GR);
    return m_small;
	}
  else if ( c == N_CAP_GR){
    print_it_please(N_SMALL_GR);
    return N_cap;
	}
  else if ( c == N_SMALL_GR){
    print_it_please(N_SMALL_GR);
    return n_small;
	}
  else{
    print_it_please(N_SMALL_GR);
    print_it_please(c);
    return any;
	}
}

enum FSM ((*action[])(int c)) =  { dflt, M, N, m, n };

int main(){
	state = any;
	int character;
	while((character = getchar()) != EOF ){
		state = (action[state])(character);
	}
	return 0;
}
