#include "Audio.h"



using namespace std;

int main(int argc,char* argv[]){

	int sampleRateInHz = atoi(argv[2]);
	int bitCount = atoi(argv[4]);
	typename T;
	int CH = atoi(argv[6]);
	string outName = "out.raw";
	int x = 7;
	if(CH == 1){
		if(bitCount == 8){
			if(string(argv[7])=="-o"){
			outName = string(argv[8]);
			x = 9;
			}

			if(string(argv[x])=="-add"){
				Audio<int8_t,1> a1;
				Audio<int8_t,1> a2;
				Audio<int8_t,1> a3;

				a1.load(string(argv[x+1]));
				a2.load(string(argv[x+2]));

				a3 = a1+a2;
				a3.save(outName);
			}
			else if(string(argv[x])=="-cut"){
				Audio<int8_t,1> a1;
				Audio<int8_t,1> a2;
		
				a1.load(string(argv[x+3]));

				int one = (int)(atof(argv[x+1])*sampleRateInHz);
				int two = (int)(atof(argv[x+2])*sampleRateInHz);

				pair<int,int> F = make_pair(one,two);

				a2 = a1^F;

				a2.save(outName);		
			}
			else if(string(argv[x])=="radd"){
				Audio<int8_t,1> a1;
				Audio<int8_t,1> a2;
				Audio<int8_t,1> a3;

				a1.load(string(argv[x+5]));
				a2.load(string(argv[x+6]));

				int r1 = (int)(atof(argv[x+1])*sampleRateInHz);
				int r2 = (int)(atof(argv[x+2])*sampleRateInHz);

				pair<int,int> i = make_pair(r1,r2);

				int s1 = (int)(atof(argv[x+3])*sampleRateInHz);
				int s2 = (int)(atof(argv[x+4])*sampleRateInHz);

				pair<int,int> j = make_pair(s1,s2);

				a3 = a1.rAdd(i,j,a2);
				a3.save(outName);
			}
			else if(string(argv[x])=="-cat"){
				Audio<int8_t,1> a1;
				Audio<int8_t,1> a2;
				Audio<int8_t,1> a3;

				a1.load(string(argv[x+1]));
				a2.load(string(argv[x+2]));

				a3 = a1|a2;

				a3.save(outName);
			}
			else if(string(argv[x])=="-v"){
				Audio<int8_t,1> a1;
				Audio<int8_t,1> a2;
				a1.load(argv[x+3]);
			
				float r1 = atof(argv[x+1]);
				float r2 = atof(argv[x+2]);

				pair<float,float> F = make_pair(r1,r2);
				a2 = a1*F;

				a2.save(outName);
			}
			else if(string(argv[x])=="-rev"){
				Audio<int8_t,1> a1;
				a1.load(string(argv[x+1]));
				a1.reverse();

				a1.save(outName);					
			}
			else if(string(argv[x])=="-rms"){
				Audio<int8_t,1> a1;
				a1.load(string(argv[x+1]));

				float heloo = a1.rms();

				cout<<heloo<<endl;
			}
			else if(string(argv[x])=="-norm"){
				Audio<int8_t,1> a1;
				//Audio<int8_t,1> a2;
				a1.load(argv[x+3]);

				float r1 = atof(argv[x+1]);
				float r2 = atof(argv[x+2]);

				pair<float,float> F = std::make_pair(r1,r2);

				a1.normalise(F);
				a1.save(outName);
			}
		}
		else{
			if(string(argv[7])=="-o"){
				outName = string(argv[8]);
				x = 9;
			}

			if(string(argv[x])=="-add"){
				Audio<int16_t,1> a1;
				Audio<int16_t,1> a2;
				Audio<int16_t,1> a3;

				a1.load(string(argv[x+1]));
				a2.load(string(argv[x+2]));

				a3 = a1+a2;
				a3.save(outName);
			}
			else if(string(argv[x])=="-cut"){
				Audio<int16_t,1> a1;
				Audio<int16_t,1> a2;
		
				a1.load(string(argv[x+3]));

				int one = (int)(atof(argv[x+1])*sampleRateInHz);
				int two = (int)(atof(argv[x+2])*sampleRateInHz);

				pair<int,int> F = make_pair(one,two);

				a2 = a1^F;		
			}
			else if(string(argv[x])=="radd"){
				Audio<int16_t,1> a1;
				Audio<int16_t,1> a2;
				Audio<int16_t,1> a3;

				a1.load(string(argv[x+5]));
				a2.load(string(argv[x+6]));

				int r1 = (int)(atof(argv[x+1])*sampleRateInHz);
				int r2 = (int)(atof(argv[x+2])*sampleRateInHz);

				pair<int,int> i = make_pair(r1,r2);

				int s1 = (int)(atof(argv[x+3])*sampleRateInHz);
				int s2 = (int)(atof(argv[x+4])*sampleRateInHz);

				pair<int,int> j = make_pair(s1,s2);

				a3 = a1.rAdd(i,j,a2);
				a3.save(outName);
			}
			else if(string(argv[x])=="-cat"){
				Audio<int16_t,1> a1;
				Audio<int16_t,1> a2;
				Audio<int16_t,1> a3;

				a1.load(string(argv[x+1]));
				a2.load(string(argv[x+2]));

				a3 = a1|a2;

				a3.save(outName);
			}
			else if(string(argv[x])=="-v"){
				Audio<int16_t,1> a1;
				Audio<int16_t,1> a2;
				a1.load(string(argv[x+3]));
			
				float r1 = atof(argv[x+1]);
				float r2 = atof(argv[x+2]);

				pair<float,float> F = make_pair(r1,r2);
				a2 = a1*F;

				a2.save(outName);
			}
			else if(string(argv[x])=="-rev"){
				Audio<int16_t,1> a1;
				a1.load(string(argv[x+1]));
				a1.reverse();

				a1.save(outName);			
			}
			else if(string(argv[x])=="-rms"){
				Audio<int16_t,1> a1;
				a1.load(string(argv[x+1]));

				float heloo = a1.rms();

				cout<<heloo<<endl;
			}
			else if(string(argv[x])=="-norm"){
				Audio<int16_t,1> a1;
				//Audio<int8_t,1> a2;
				a1.load(string(argv[x+3]));

				float r1 = atof(argv[x+1]);
				float r2 = atof(argv[x+2]);

				pair<float,float> F = std::make_pair(r1,r2);

				a1.normalise(F);
				a1.save(outName);
			}
		}
	}
	else if(CH == 2){
		if(bitCount == 8){
			if(string(argv[7])=="-o"){
			outName = string(argv[8]);
			x = 9;
			}

			if(string(argv[x])=="-add"){
				Audio<int8_t,2> a1;
				Audio<int8_t,2> a2;
				Audio<int8_t,2> a3;

				a1.load(string(argv[x+1]));
				a2.load(string(argv[x+2]));

				a3 = a1+a2;
				a3.save(outName);
			}
			else if(string(argv[x])=="-cut"){
				Audio<int8_t,2> a1;
				Audio<int8_t,2> a2;
		
				a1.load(string(argv[x+3]));

				int one = (int)(atof(argv[x+1])*sampleRateInHz);
				int two = (int)(atof(argv[x+2])*sampleRateInHz);

				pair<int,int> F = make_pair(one,two);

				a2 = a1^F;

				a2.save(outName);		
			}
			else if(string(argv[x])=="radd"){
				Audio<int8_t,2> a1;
				Audio<int8_t,2> a2;
				Audio<int8_t,2> a3;

				a1.load(string(argv[x+5]));
				a2.load(string(argv[x+6]));

				int r1 = (int)(atof(argv[x+1])*sampleRateInHz);
				int r2 = (int)(atof(argv[x+2])*sampleRateInHz);

				pair<int,int> i = make_pair(r1,r2);

				int s1 = (int)(atof(argv[x+3])*sampleRateInHz);
				int s2 = (int)(atof(argv[x+4])*sampleRateInHz);

				pair<int,int> j = make_pair(s1,s2);

				a3 = a1.rAdd(i,j,a2);
				a3.save(outName);
			}
			else if(string(argv[x])=="-cat"){
				Audio<int8_t,2> a1;
				Audio<int8_t,2> a2;
				Audio<int8_t,2> a3;

				a1.load(string(argv[x+1]));
				a2.load(string(argv[x+2]));

				a3 = a1|a2;

				a3.save(outName);
			}
			else if(string(argv[x])=="-v"){
				Audio<int8_t,2> a1;
				Audio<int8_t,2> a2;
				a1.load(argv[x+3]);
			
				float r1 = atof(argv[x+1]);
				float r2 = atof(argv[x+2]);

				pair<float,float> F = make_pair(r1,r2);
				a2 = a1*F;

				a2.save(outName);
			}
			else if(string(argv[x])=="-rev"){
				Audio<int8_t,2> a1;
				a1.load(string(argv[x+1]));
				a1.reverse();

				a1.save(outName);					
			}
			else if(string(argv[x])=="-rms"){
				Audio<int8_t,2> a1;
				a1.load(string(argv[x+1]));

				//float heloo = a1.rms();

				cout<<"Doesn't  WORK"<<endl;
			}
			else if(string(argv[x])=="-norm"){
				Audio<int8_t,2> a1;
				//Audio<int8_t,1> a2;
				a1.load(argv[x+3]);

				float r1 = atof(argv[x+1]);
				float r2 = atof(argv[x+2]);

				pair<float,float> F = std::make_pair(r1,r2);

				//a1.normalise(F);
				a1.save(outName);
			}
		}
		else{
			if(string(argv[7])=="-o"){
				outName = string(argv[8]);
				x = 9;
			}

			if(string(argv[x])=="-add"){
				Audio<int16_t,2> a1;
				Audio<int16_t,2> a2;
				Audio<int16_t,2> a3;

				a1.load(string(argv[x+1]));
				a2.load(string(argv[x+2]));

				a3 = a1+a2;
				a3.save(outName);
			}
			else if(string(argv[x])=="-cut"){
				Audio<int16_t,2> a1;
				Audio<int16_t,2> a2;
		
				a1.load(string(argv[x+3]));

				int one = (int)(atof(argv[x+1])*sampleRateInHz);
				int two = (int)(atof(argv[x+2])*sampleRateInHz);

				pair<int,int> F = make_pair(one,two);

				a2 = a1^F;		
			}
			else if(string(argv[x])=="radd"){
				Audio<int16_t,2> a1;
				Audio<int16_t,2> a2;
				Audio<int16_t,2> a3;

				a1.load(string(argv[x+5]));
				a2.load(string(argv[x+6]));

				int r1 = (int)(atof(argv[x+1])*sampleRateInHz);
				int r2 = (int)(atof(argv[x+2])*sampleRateInHz);

				pair<int,int> i = make_pair(r1,r2);

				int s1 = (int)(atof(argv[x+3])*sampleRateInHz);
				int s2 = (int)(atof(argv[x+4])*sampleRateInHz);

				pair<int,int> j = make_pair(s1,s2);

				a3 = a1.rAdd(i,j,a2);
				a3.save(outName);
			}
			else if(string(argv[x])=="-cat"){
				Audio<int16_t,2> a1;
				Audio<int16_t,2> a2;
				Audio<int16_t,2> a3;

				a1.load(string(argv[x+1]));
				a2.load(string(argv[x+2]));

				a3 = a1|a2;

				a3.save(outName);
			}
			else if(string(argv[x])=="-v"){
				Audio<int16_t,2> a1;
				Audio<int16_t,2> a2;
				a1.load(string(argv[x+3]));
			
				float r1 = atof(argv[x+1]);
				float r2 = atof(argv[x+2]);

				pair<float,float> F = make_pair(r1,r2);
				a2 = a1*F;

				a2.save(outName);
			}
			else if(string(argv[x])=="-rev"){
				Audio<int16_t,2> a1;
				a1.load(string(argv[x+1]));
				a1.reverse();

				a1.save(outName);			
			}
			else if(string(argv[x])=="-rms"){
				Audio<int16_t,2> a1;
				a1.load(string(argv[x+1]));

				//float heloo = a1.rms();

				cout<<"DOESN't WORK"<<endl;
			}
			else if(string(argv[x])=="-norm"){
				Audio<int16_t,2> a1;
				//Audio<int8_t,1> a2;
				a1.load(string(argv[x+3]));

				float r1 = atof(argv[x+1]);
				float r2 = atof(argv[x+2]);

				pair<float,float> F = std::make_pair(r1,r2);

				//a1.normalise(F);
				a1.save(outName);
			}
		}
	}
}
