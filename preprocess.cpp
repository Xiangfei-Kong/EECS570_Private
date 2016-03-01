#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;


	struct movie_t{
		int	movie_ID;
	        string	title;
		string 	genre;
	};

	struct rating_t{
		int 	user_ID;
		int	movie_ID;
		double	rating;
		long	timestamp;
	};

	struct	link_t{
		int	movie_ID;
		int 	imdb_ID;
		int	tmdb_ID;
	};

	struct	tag_t{
		int	user_ID;
		int	movie_ID;
		string	tag;
		long	timestamp;
	};

class preprocess {


public:
	vector<movie_t> movie() {
		vector<movie_t> movie_info;
		ifstream infilemovie;
		infilemovie.open("/home/xfkong/eecs570/Final_Project/ml/movies.csv");
	
		string s;
		getline(infilemovie,s);
		
		while(infilemovie) {
			
			if(!getline(infilemovie,s)) break;
		
			istringstream ss(s);
			string	field;
			movie_t record;

			getline(ss,field,',');		
			record.movie_ID = stoi(field);	
			getline(ss,field,',');		
			record.title = field;	
			getline(ss,field,',');		
			record.genre = field;
			movie_info.push_back(record);
		}
	
		for (int i=0; i < 2; i++) {
			cout << movie_info[i].movie_ID << ' ' << movie_info[i].title << ' ' << movie_info[i].genre << endl;
		}
	
		return movie_info;
	}


	vector<rating_t> rating() {
		vector<rating_t> rating_info;
		ifstream infilerating;
		infilerating.open("/home/xfkong/eecs570/Final_Project/ml/ratings.csv");
	
		string s;
		getline(infilerating,s);
		
		while(infilerating) {
			
			if(!getline(infilerating,s)) break;
		
			istringstream ss(s);
			string		field;
			rating_t 	record;


			getline(ss,field,',');		
			//cout << field << ' ';
			record.user_ID = stoi(field);	
			getline(ss,field,',');			
			//cout << field << endl;
			record.movie_ID = stoi(field);	
			getline(ss,field,',');		
			record.rating = stod(field);	
			getline(ss,field,',');		
			record.timestamp = stol(field);
			rating_info.push_back(record);
		}

		for (int i=0; i < 2; i++) {
			cout << rating_info[i].user_ID << ' ' << rating_info[i].movie_ID << ' ' << rating_info[i].rating << ' ' << rating_info[i].timestamp << endl;
		}

		return rating_info;
	}

	
	vector<link_t> link() {
		vector<link_t> link_info;
		ifstream infilelink;
		infilelink.open("/home/xfkong/eecs570/Final_Project/ml/links.csv");
	
		string s;
		getline(infilelink,s);
		
		while(infilelink) {
			
			if(!getline(infilelink,s)) break;
		
			istringstream 	ss(s);
			string		field;
			link_t 	record;

			getline(ss,field,',');	
			//cout << field << endl;	
			record.movie_ID = stoi(field);
			getline(ss,field,',');
		       	record.imdb_ID = stoi(field);
			getline(ss,field,',');
		       	record.tmdb_ID = stoi(field);
			link_info.push_back(record);
		}
		
		for (int i=0; i < 2; i++) {
			cout << link_info[i].movie_ID << ' ' << link_info[i].imdb_ID << ' ' << link_info[i].tmdb_ID << endl;
		}
		
		return link_info;
	}

	
	vector<tag_t> tag() {
		vector<tag_t> tag_info;
		ifstream infiletag;
		infiletag.open("/home/xfkong/eecs570/Final_Project/ml/tags.csv");
	
		string s;
		getline(infiletag,s);
		
		while(infiletag) {
			
			if(!getline(infiletag,s)) break;
		
			istringstream ss(s);
			string		field;
			tag_t	 	record;

			getline(ss,field,',');		
			//cout << field << ' ';
			record.user_ID = stoi(field);	
			getline(ss,field,',');			
			//cout << field << endl;
			record.movie_ID = stoi(field);	
			getline(ss,field,',');		
			record.tag = field;	
			getline(ss,field,',');		
			record.timestamp = stol(field);
			tag_info.push_back(record);
		}
		
		for (int i= 0; i < 2; i++) {
			cout << tag_info[i].user_ID << ' ' << tag_info[i].movie_ID << ' ' << tag_info[i].tag << ' ' << tag_info[i].timestamp << endl;
		}
		
		return tag_info;
	}

};

int main() {
	preprocess process;	
	vector<movie_t> 	movie_info;
	vector<rating_t> 	rating_info;
	vector<tag_t> 		tag_info;
	vector<link_t> 		link_info;

	movie_info = process.movie();
	tag_info = process.tag();
	link_info = process.link();
	rating_info = process.rating();

	return 0;
}



























