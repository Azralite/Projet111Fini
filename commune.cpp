#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.h"
#include "tableau-donnees-csv.h"
#include <MLV/MLV_image.h>
#include <MLV/MLV_window.h>
#include <MLV/MLV_time.h>
#include <MLV/MLV_shape.h>
#include <MLV/MLV_text.h>
using namespace std;

int main(){
	double cote = 1000;
	double latMax = 8.1187033;
	double latMin = -4.7210;
	double lonMax = 51.0733106;
	double lonMin = 42.357686;
	MLV_create_window("Exercice 9", "Fenetre", cote, cote);
        MLV_clear_window( MLV_COLOR_GREY95); 
	vector<vector<string>> tab_str = litTableauCSV("donnees/communes.csv");
	vector<string> latitude_str = colonne(tab_str, 4);
	vector<string> longitude_str = colonne(tab_str, 5);
	vector<string> population_str  = colonne(tab_str, 10);
	vector<double> latitude = conversionDouble(latitude_str);
	vector<double> longitude = conversionDouble(longitude_str);
	vector<double> population = conversionDouble(population_str);
	vector<vector<double>> tab;
	tab = vector<vector<double>>(latitude.size());
	for(int i = 0; i < latitude.size(); i++){
		vector<double> v = {(latitude[i]-latMin)*cote/(latMax-latMin), (longitude[i]-lonMax)*cote/(lonMin-lonMax), population[i]};
		tab[i] =  v;
	}

	//Légende
	MLV_draw_filled_circle(10, cote - 50, 1, MLV_COLOR_BLACK);
	MLV_draw_text(20, cote -57,"  Commune entre 0 et 10 000 habitants", MLV_COLOR_BLACK);
	MLV_draw_filled_circle(10, cote - 40, 3, MLV_COLOR_BLACK);
	MLV_draw_text(20, cote -46,"  Commune entre 10 000 et 50 000 habitants", MLV_COLOR_BLACK);
	MLV_draw_filled_circle(10, cote - 27, 7, MLV_COLOR_BLACK);
	MLV_draw_text(20, cote -34,"  Commune entre 50 000 et 100 000 habitants", MLV_COLOR_BLACK);
	MLV_draw_filled_circle(10, cote - 10, 10, MLV_COLOR_BLACK);
	MLV_draw_text(20, cote -17,"  Commune de plus de 100 000 habitants", MLV_COLOR_BLACK);
	MLV_update_window();
	
	for(int i =0; i < tab.size(); i++){
		if(tab[i][2] < 10){
			MLV_draw_filled_circle(tab[i][0], tab[i][1], tab[i][2]/10 , MLV_COLOR_BLACK);
			MLV_update_window();
		}
		if(10 < tab[i][2] && tab[i][2] < 50){
			MLV_draw_filled_circle(tab[i][0], tab[i][1], tab[i][2]/10, MLV_COLOR_BLACK);
			MLV_update_window();
		}
		if(50 < tab[i][2] && tab[i][2] < 100){
			MLV_draw_filled_circle(tab[i][0], tab[i][1], tab[i][2]/10, MLV_COLOR_BLACK);
			MLV_update_window();
		}
		if(tab[i][2]>100){
			MLV_draw_filled_circle(tab[i][0], tab[i][1], tab[i][2]/10, MLV_COLOR_BLACK);
			MLV_update_window();
		}
		
	}
	MLV_wait_seconds(20);


	return 0;
}
