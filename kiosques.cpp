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
	double latMax = 48.90;
	double latMin = 48.81;
	double lonMax = 2.42;
	double lonMin = 2.24;
	MLV_create_window("Kiosque  et Pharmacie à Paris", "Kiosque et Pharma", cote, cote);
        MLV_clear_window( MLV_COLOR_GREY95); 
	vector<vector<string>> tab_str = litTableauCSV("donnees/kiosques.csv");
	vector<string> latitude_str = colonne(tab_str, 6);
	vector<string> longitude_str = colonne(tab_str, 7);
	vector<double> latitude = conversionDouble(latitude_str);	
	vector<double> longitude = conversionDouble(longitude_str);
	vector<vector<double>> tab;
	tab = vector<vector<double>>(latitude.size());
	for(int i = 0; i < latitude.size(); i++){
		vector<double> v = {(latitude[i]-latMin)*cote/(latMax-latMin), (longitude[i]-lonMax)*cote/(lonMin-lonMax)};
		tab[i] =  v;
	}


	vector<vector<string>> tab2_str = litTableauCSV("donnees/pharmacie.csv");
	vector<string> latitude2_str = colonne(tab2_str, 20);
	vector<string> longitude2_str = colonne(tab2_str, 21);
	vector<double> latitude2 = conversionDouble(latitude2_str);	
	vector<double> longitude2 = conversionDouble(longitude2_str);
	vector<vector<double>> tab2;
	tab2 = vector<vector<double>>(latitude2.size());
	for(int i = 0; i < latitude2.size(); i++){
		vector<double> v = {(latitude2[i]-latMin)*cote/(latMax-latMin), (longitude2[i]-lonMax)*cote/(lonMin-lonMax)};
		tab2[i] =  v;
	}

	MLV_draw_filled_circle(10, cote - 50, 5, MLV_COLOR_BLACK);
	MLV_draw_text(20, cote -57,"  Kiosque", MLV_COLOR_BLACK);
	MLV_draw_filled_circle(10, cote - 40, 5, MLV_COLOR_BLUE);
	MLV_draw_text(20, cote -44,"  Pharmacie", MLV_COLOR_BLACK);

	
	for(int i =0; i < tab.size(); i++){
			MLV_draw_filled_circle(tab[i][0], tab[i][1], 3, MLV_COLOR_BLACK);
			MLV_update_window();
		
	}

	for(int i =0; i < tab2.size(); i++){
			MLV_draw_filled_circle(tab2[i][0], tab2[i][1], 3, MLV_COLOR_BLUE);
			MLV_update_window();
		
	}
	MLV_wait_seconds(10);


	return 0;
}

