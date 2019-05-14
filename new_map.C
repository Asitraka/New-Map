
bool comparison(double a, double b){
 return (a<b);
}
std::map<double, std::vector<std::vector<double>>> New_map(std::map<double, std::vector<std::vector<double>>> old_map){ 
  std::map<double, std::vector<std::vector<double>>> output;
  for(std::map<double,std::vector<std::vector<double>>>::iterator Measurements = old_map.begin(); Measurements != old_map.end(); ++ Measurements){
    double TrueE=Measurements->first;
    std::vector<std::vector<double>> measurements = Measurements->second;
    std::vector<double> rank_Z ;
    std::vector<double> rank_Y ;
    std::vector<double> rank_X ;
    std::vector<double> coordinate ;
    std::vector<std::vector<double>> New_measurements;
    if(measurements.size()>3){
      for(int i = 0; i < measurements.size(); i++) {

	double z=(measurements.at(i))[2];
 	double y=(measurements.at(i))[1];
	double x=(measurements.at(i))[0];
        rank_Z.push_back(z);
        rank_Y.push_back(y);
        rank_X.push_back(x);

	}
      std::sort(rank_Z.begin(),rank_Z.end(),comparison);
//      std::sort(rank_Y.begin(),rank_Y.end(),comparison);
//      std::sort(rank_X.begin(),rank_X.end(),comparison);

      for(int i = 0; i < rank_Z.size(); i++) {

           coordinate.push_back(rank_X.at(i));
           coordinate.push_back(rank_Y.at(i));
           coordinate.push_back(rank_Z.at(i));
           New_measurements.push_back(coordinate);
	}
    }
    output.emplace(TrueE, New_measurements);
  }

  return output;
}
