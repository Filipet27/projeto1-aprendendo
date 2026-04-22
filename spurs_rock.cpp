#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x,y,z,w,k=0,t1,t2;
    vector<int>cont(100,0),receb(100,0),feitos(100,0),average(100,0),ordem(100);
    map<int,int>conv;
    cin>>n;
    while(n!=0){
        for(int j=0;j<(n*(n-1)/2);j++){
            cin>>x>>y>>z>>w;
        }
        if(y>w){
            t1=0;
            t2=0;
            cont[x]+=2;
            receb[x]+=w;
            feitos[x]+=y;
            for(int i=0;i<ordem.size();i++){

                if(ordem[i]!=x){
                    t1++;
                }
                else if(t1>=99){
                    ordem.push_back(x);
                }
            }
            
            if(w!=0){
                average[x]+=(y/w);
            }
            else
            {
                average[x]+=y;
            }
            for(int i=0;i<ordem.size();i++){

                if(ordem[i]!=z){
                    t2++;
                }
                else if(t2>=99){
                    ordem.push_back(z);
                }
            }

            cont[z]+=1;
            receb[z]+=y;
            feitos[z]+=w;
            ordem.push_back(z);
            if(y!=0){
                average[z]+=(w/y);
            }
            else
            {
                average[z]+=w;
            }
        }
        else if(y<w){
            cont[x]+=1;
            receb[x]+=w;
            feitos[x]+=y;

            cont[z]+=2;
            receb[z]+=y;
            feitos[z]+=w;
        }
        for(int j=1;j<100;j++){
            for(int k=1;k<100;k++){
                if(cont[k]!=0&&cont[k]>=cont[k-1]){
                    swap(ordem[k],ordem[k-1]);
                    swap(cont[k],cont[k-1]);
                    if(cont[k]==cont[k-1]&&average[k]>=average[k-1]){
                        swap(cont[k],cont[k-1]);
                        swap(ordem[k],ordem[k-1]);

                        if(average[k]==average[k-1]&&feitos[k]>=feitos[k-1]){
                            swap(cont[k],cont[k-1]);
                            swap(ordem[k],ordem[k-1]);

                            if(feitos[k]==feitos[k-1]&&k<k-1){
                                swap(cont[k],cont[k-1]);
                                swap(ordem[k],ordem[k-1]);

                            }
                        }
                    }
                }
               
            }
        }
        k++;
        cout<<"Instancia "<<k<<endl;

        for(int i=0;i<100;i++){
            if(cont[i]!=0){
               cout<<ordem[i]<<" ";
            }
            

        }


        cin>>n;
    }




    return 0;
}