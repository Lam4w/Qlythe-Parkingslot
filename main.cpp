#include <iostream>
#include <bits/stdc++.h>
#include <vector>
 using namespace std;

 string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *gmtime(&now);
    tstruct.tm_hour += 7;
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
 class ParkingTicket
 {
 private:
     bool statusthe;
 protected:
    string ticketNumber;
    int ticketId;
    string licenseNumber;
    string parkingspotId;
    static inline vector<int> ids ={1,2,3,4,5};
 public:
    static bool checkID(int ticketId)  //kiem tra id
    {
        for (int i = 0; i <= ids.size(); ++i)
        {
            if (ticketId == i) {
                return true;
            }
        }
        return false;
    }
    static int createID()  //tao id the moi
    {
        int ticketId = (rand() % (999 - 1 + 1)) + 1;
        while (checkID(ticketId) && ids.size() > 0)
        {
            ticketId = (rand() % (999 - 1 + 1)) + 1;
        }
        ids.push_back(ticketId);
        return ticketId;
    }
    string getticketNumber()
    {
        return this->ticketNumber;
    }
    void setticketNumber(string ticketNumber)
    {
        this->ticketNumber = ticketNumber;
    }
    int getticketid()
    {
        return this->ticketId;
    }
    void setticketId(int ticketId)
    {
        this->ticketId = ticketId;
    }
    string getlicenseNumber()
    {
        return this->licenseNumber;
    }
    void setlicenseNumber(string licenseNumber)
    {
        this->licenseNumber = licenseNumber;
    }
    string getparkingspotId()
    {
        return this->parkingspotId;
    }
    void setparkingspotId(string parkingspotId)
    {
        this->parkingspotId = parkingspotId;
    }


 };


 class theravao :public ParkingTicket
 {
 private:
     int id;
 public:
    theravao()
    {
        string ticketNumber;
        string licenseNumber;
        string parkingspotId;
        cout <<"Nhap thong tin ve xe"<< endl;
        cout<<"Nhap ID the: ";
        cin>> id;
        this->setticketId(id);
        cout <<"Nhap so ve xe: ";
        cin >> ticketNumber;
        cin.ignore(1);
        this->setticketNumber(ticketNumber);
        cout <<"Nhap bien so xe: ";
        cin >> licenseNumber;
        cin.ignore(1);
        this->setlicenseNumber(licenseNumber);
        cout <<"Nhap vi tri do xe: ";
        cin >> parkingspotId;
        cin.ignore(1);
        this->setparkingspotId(parkingspotId);
    }
 };


vector<theravao> dstheravao;


class Logs {
  private:
    ParkingTicket parkingticket;
    string timeVao;
    string timeRa;
    bool status;
    bool statusthe;

  public:
    Logs(ParkingTicket parkingticket, string timeVao) {
        this->parkingticket = parkingticket;
        this->timeVao = timeVao;
        this->timeRa = "xe chua Ra";
        this->status = false;
        this->statusthe = true;
    }
    void diRa() {
        this->timeRa = currentDateTime();
        this->status = true;
    }
    int getID()
    {
        return parkingticket.getticketid();
    }
    string getLicensenum()
    {
        return parkingticket.getlicenseNumber();
    }
    string getTimeVao()
    {
        return this->timeVao;
    }
    string getTimeRa()
    {
        return this->timeRa;
    }
    bool getStatus()
    {
    return this->status;
    }
    bool settrue()
    {
        this->statusthe = true;
        cout << "The da duoc mo. \n";
    }
    bool setfalse()
    {
        this->statusthe = false;
        cout << "The da dc khoa. \n";
    }
    bool getstatusthe()
    {
        return this->statusthe;
    }
};


vector<Logs> logs;


void ravao()
{
    int Id;
    int tg = 0;
    cout << "Nhap ID the: ";
    cin >> Id;
    if (!ParkingTicket::checkID(Id))
    {
    cout << "ID cua the khong ton tai. \n";
    }
    else if (logs.size() > 0)
    {
        for (int i = 0; i <= logs.size(); ++i)
        {
            if (Id == logs[i].getID() && logs[i].getstatusthe() == false)
            {
                cout << "The da bi khoa.\n";
                cout << "Press Enter to Continue \n";
                cin.ignore();
                return;
            }
            if (Id == logs[i].getID() && logs[i].getStatus() == false && logs[i].getstatusthe() == true)
            {
                logs[i].diRa();
                cout << "Xac nhan xe di ra.\n";
                cout << "Press Enter to Continue \n";
                cin.ignore();
                return;
            }
        }
    }
    dstheravao.push_back(theravao());
    ParkingTicket parkingticket;
    for (theravao i : dstheravao)
    {
        if (Id == i.getticketid())
        {
                     parkingticket = i;
        }
    }

    logs.push_back(Logs(parkingticket, currentDateTime()));
    cout << "Xac nhan xe di vao.\n";

    cout << "Press Enter to Continue \n";
    cin.ignore();
}


void danhsach()
{
    cout << "ID ve xe\t\Bien so xe\t\tGio vao\t\t\t\t\t\t\Gio ra\n";
    for (Logs i : logs)
    {
        cout <<i.getID()<<"\t\t"<<i.getLicensenum()<<"\t\t\t"<<i.getTimeVao()<<"\t\t\t"<<i.getTimeRa()<<endl;
    }
    cout << "Press Enter to Continue";
    cin.ignore();
}


void capnhap()
{
    int Id;
    cout << "Nhap Id the can cap nhap: ";
    cin >> Id;
    if (!ParkingTicket::checkID(Id))
    {
        cout << "ID the khong ton tai. \n";
    }
    else if (logs.size() > 0)
        {
            for (int i = 0; i <= logs.size(); ++i)
            {
                if (Id == logs[i].getID())
                {
                    if (logs[i].getstatusthe() == true)
                    {
                        logs[i].setfalse();
                    }
                    else
                    {
                        logs[i].settrue();
                    }
                }
            }
        }
    cout << "Press Enter to Continue \n";
    cin.ignore();
}
int main() {
    int input;
    while (true) {
        cout << "1- Ra Vao xe \n";
        cout << "2- danh sach xe ra vao\n";
        cout << "3- cap nhap trang thai the\n";
        cout << "4- Thoat\n";
        cin >> input;
        cin.ignore(1);

        switch (input) {
            case 1:
                ravao();
                break;
            case 2:
                danhsach();
                break;
            case 3:
                capnhap();
                break;
            case 4:
                break;
        }
    }
}




