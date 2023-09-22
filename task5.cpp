#include <bits/stdc++.h>

using namespace std;

vector<string> movies = {"Movie No. 1","The Second Movie","Movie the Third","Fantastic Fourth Moive","The Movies 5","6-nema","This is the 7th Movie","Eight ways to watch Movie","The 9 rings of Movies","The tenth Descendant of Movies"};
vector<string> dates = {"01/10/2023","02/10/2023","03/10/2023","04/10/2023","05/10/2023"} ;
vector<string> timings = {"08:00","11:00","14:00","17:00","20:00","23:00"};
unordered_map<string,vector<vector<bool>>> seats; vector<string> booked;

int main() 
{
    for(auto &s:movies) for(auto &t:timings) for(auto &d:dates)  seats[s+"\\"+t+"\\"+d] = vector<vector<bool>> (10,vector<bool>(10,1));
    int choice,n,r,c,i=0,j=0;string book,bookseat,x,y,z;vector<string> vs;char quitChoice;vector<int> arr;
    do {
        
        cout<<"\n\033[1;31m\n _       __     __                             __           __  ___           _         _______      __        __     ____              __   _                _____       __               \n";
        cout<<"\033[33m| |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _   __(_)__     /_  __(_)____/ /_____  / /_   / __ )____  ____  / /__(_)___  ____ _   / ___/__  __/ /____  ____ ___ \n";
        cout<<"\033[1;32m| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/ / __ \\ | / / / _ \\     / / / / ___/ //_/ _ \\/ __/  / __  / __ \\/ __ \\/ //_/ / __ \\/ __ `/   \\__ \\/ / / / __/ _ \\/ __ `__ \\\n";
        cout<<"\033[1;36m| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / |/ / /  __/    / / / / /__/ ,< /  __/ /_   / /_/ / /_/ / /_/ / ,< / / / / / /_/ /   ___/ / /_/ / /_/  __/ / / / / /\n";
        cout<<"\033[1;34m|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\____/|___/_/\\___/    /_/ /_/\\___/_/|_|\\___/\\__/  /_____/\\____/\\____/_/|_/_/_/ /_/\\__, /   /____/\\__, /\\__/\\___/_/ /_/ /_/ \n";
        cout<<"\033[1;35m                                                                                                                                                 /____/         /____/                                    \n\n";
        cout << "\033[21;3;33m1. Book Tickets.\n";
        cout << "2. View your tickets.\n";
        cout << "3. View movie listings.\n";
        cout << "4. Cancel bookings.\n";
        cout << "5. Quit\n";
        cout << "\033[3;32mEnter your choice: \033[0m";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"\n\n\033[35mWelcome to ticket booking system. The available movies are: \n";
                for(auto &s:movies) cout<<s<<'\n';
                cout<<"\nChoose your movie title :\t";
                cin>>x;cout<<"\n\nThe available dates are :\n";
                for(auto &s:dates) cout<<s<<'\t';
                cout<<"\nChoose the date for which you want to book :\t";cin>>z;
                cout<<"\n\nThe timings for this movie that day are :\n";
                for(auto &s:timings) cout<<s<<'\t';
                cout<<"\nChoose the suitable timing :\t";cin>>y;
                book = x+'\\'+y+'\\'+z;
                //Display the available seats
                for(i=0;i<10;i++){for(j=0;j<10;j++){
                    string s = to_string(i+1)+(char)(j+'A');if(s.length()<3) s='0'+s;
                    cout<<(seats[book][i][j] ?"\033[32m" :"\033[31m")<<s<<"\033[0m";
                    cout<<((j==1 or j==4 or j==7) ?"\t\t" :"\t");}cout<<"\n\n";}
                cout<<"\n\033[35mThe green seats are available, the red seats are not. Please choose how many tickets you want to buy? \t";cin>>n;
                cout<<"\nNow enter the seat number(s) you want to book (separate with spaces) :\n";vs.resize(n,"");for(int i=0;i<n;i++) cin>>vs[i];
                //Booking infromation input and processing
                sort(vs.begin(),vs.end());for(string &s:vs){ if(s.length()<3) s='0'+s;
                    r=stoi(s.substr(0,2))-1,c=(int)(s.back()-'A');
                    if(r<0 or r>9 or c<0 or c>9) cout<<"\033[1;31mSeat "<<s<<" is invalid. Please write valid seat numbers.\n";
                    else if(seats[book][r][c]==0) cout<<"\033[1;31mSeat not available. Please choose green seats only.\n";
                    else {
                        seats[book][r][c] = 0;bookseat = book + '\\' + s;booked.push_back(bookseat);
                        cout<<"\033[1;32mBooked seat "<<s<<"\033[0m\n";
                    }
                }
                break;
            case 2:
                if(booked.empty()){cout<<"\033[1;31mYou do not have any booked tickets yet. Book few tickets to continue.\033[0m\n";break;}
                cout<<"\033[3;36mYour booked tickets are\n\n";sort(booked.begin(),booked.end());
                for(auto &tkt:booked) {for(const char &c:tkt) cout<<(c=='\\' ?' ' :c  );cout<<'\n';}
                cout<<"\033[0m\n";break;
            case 3:
                cout<<"\033[1;34mNow showing:\n";
                for(string &s:movies) cout<<s<<'\n';
                cout<<"Booking Timings:\n";
                for(string &s:timings) cout<<s<<'\t';cout<<'\n';
                cout<<"Book now for dates:\n";
                for(string &s:dates) cout<<s<<'\t';cout<<'\n';
                cout<<"\033[0m";
                break;
            case 4:
                if(booked.empty()){cout<<"\033[1;31mYou do not have any booked tickets yet. Book few tickets to continue.\033[0m\n";break;}
                cout<<"\n\033[1;33mYour tickets are :\n\n";
                i=1;for(auto &tkt:booked){
                    cout<<i<<":\t";i++;
                    for(auto &c:tkt) cout<<(c=='\\' ?' ' :c);
                    cout<<'\n';
                }
                cout<<"How mant tickets do you want to cancel?\n";cin>>n;
                if(n<1 or n>booked.size()) {cout<<"Invalid number.\n";break;}
                cout<<"Which ticket(s) do you want to cancel? Please write numbers corresponding to your cancelling ticket(s). Separate with spaces.\n";
                for(i=0;i<n;i++) cin>>j,arr.push_back(j);sort(arr.begin(),arr.end());for(auto &j:arr) {
                    j-=i+1;cout<<"You're cancelling seat"<<booked[j]<<'\n';
                    r=(stoi(booked[j].substr(booked[j].length()-3,2)))-1,c=(int)(booked[j].back()-'A');
                    for(int k=0;k<4;k++) booked[j].pop_back();
                    seats[booked[j]][r][c]=1;
                    booked.erase(next(booked.begin(),j));
                }
                break;
            case 5:
                cout << "\033[31mAre you sure you want to quit? (y/n): ";
                cin >> quitChoice;
                if (toupper(quitChoice) == 'Y') {
                    cout << "\033[1;3mGoodbye!\n\033[0m";
                    return 0;
                }
                break;
            default:
                cout << "\033[3;37mInvalid choice. Please try again.\033[0m\n";
                break;
        }
    }while(true);

    return 0;
}