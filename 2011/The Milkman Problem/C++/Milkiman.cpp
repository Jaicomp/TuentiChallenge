#include <iostream>


using namespace std;

//Mayor candidad de leche que entraría en el camión
static int best_milk = 0;



//Clase cow
	class Cow {

		public:
			Cow(){}

			void setWeight(int w){ weight = w;}
			void setProductionMilk(int m){ production_milk = m;}
			

			int getWeight(){ return weight;}
			int getProductionMilk(){ return production_milk;}

		private:
			int weight;
			int production_milk;
	};

/*
*
*	Método de BACKTRACKING que cálcula el resultado total
*
*
*/
void calculate_traverse_milk(Cow farm[], int pos, int actual_milk, int actual_w, int num_cows, int mwt){

	if (pos == num_cows) return;

	for (int i = pos; i != num_cows; i++){
		
		actual_w += farm[i].getWeight();
		
		if (actual_w < mwt){
			actual_milk += farm[i].getProductionMilk();

			if (actual_milk > best_milk){
				best_milk = actual_milk;
			}
			calculate_traverse_milk(farm, i+1, actual_milk, actual_w, num_cows, mwt);
			actual_milk -= farm[i].getProductionMilk();
		}
		actual_w -= farm[i].getWeight();

	}

}


//Para minimizar el número de parámetros que tengamos que introducir para llamar
//el algoritmo de backtracking, he creado este método alternativo que llamaremos
//en el main
void calculate_maximum_milk(Cow farm[],int num_cows,int mwt){

	return calculate_traverse_milk(farm, 0, 0, 0, num_cows, mwt);
}


//Programa principal
int main(){

	int num_cows, weight, milk, max_weight_truck;

	cout << "Number of Cows: " << endl;
	cin >> num_cows;
	Cow farm[num_cows];
	int position_cows_in_truck[num_cows];


	for (int i = 0; i < num_cows; i++){
		cout << "Introduce weight of Cow: " << i+1 << endl;
		cin >> weight;
		farm[i].setWeight(weight);
	}

	for (int i = 0; i < num_cows; i++){
		cout << "Introduce production of milk  of Cow: " << i+1 << endl;
		cin >> milk;
		farm[i].setProductionMilk(milk);
	}

	cout << "Introduce maximum weight of truck can handle: " << endl;
	cin >> max_weight_truck;

	//Calcula el número 
	calculate_maximum_milk(farm, num_cows, max_weight_truck);
	cout << "Resultado: " << best_milk << endl;
}





