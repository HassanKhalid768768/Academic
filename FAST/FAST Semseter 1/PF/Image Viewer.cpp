#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void B_Sort(int a[], int s){
    for(int i = 0; i< s-1; i++){
        for(int j= 0; j< s-2-i; j++){
            if(a[j] < a[j+1]){
                int T = a[j];
                a[j] = a[j+1];
                a[j+1] = T;
            }
        }
    }
}

struct PGMImage{
    int H, W, MaxGray;
    string Comment;
    string MagicNo;
    vector<vector<int>> ImageData;

    PGMImage(){
        cout<<"Called Automatically"<<endl;
        H = W = MaxGray = -1;
    }

    void Create(vector<vector<int>>& Img, int H, int W){
        Img = vector<vector<int>>(H);
        for(int i = 0; i< H; i++)
            Img[i] = vector<int>(W);
        return;
    }

    bool ReserveMemory(){
        // Code to create memory storage for the image
        // This code assumes that H and W have been set earlier
        cout<<W<<" "<<H<<endl;
        if(H < 0 || W < 0)
            return false;
        Create(ImageData, H, W);
        return true;
    }

    bool LoadImage(char FileName[]){
        // Code to open File, Reserve Memory and load image data in memory
        ifstream FIN(FileName);
        if(! FIN.is_open())
            return false;

        getline(FIN, MagicNo);
        getline(FIN, Comment); // reading the comment. PROBLEM HERE THE COMMENTIS OPTIONAL

        FIN >> W >> H >> MaxGray;
        if( !ReserveMemory()){
            FIN.close();
            return false;
        }

        for(int r = 0; r < H; r++){
            for(int c = 0; c < W; c++){
                FIN >> ImageData[r][c];
            }
        }

        FIN.close();
        return true;
    }

    bool SaveImage(char FileName[]){
        // Code to open File, Reserve Memory and load image data in memory
        if(H < 0)
            return false;

        ofstream FOUT(FileName);
            // Your Code to check if the file has been created for output
            // If File not created then return false

        FOUT << "P2" <<endl
             << "# Created By MB For BDS-1A and BDS-1C"<<endl
             << W <<" " <<H<<endl
             <<MaxGray<<endl;

        for(int r = 0; r < H; r++){
            for(int c = 0; c < W; c++){
                FOUT << ImageData[r][c]<<" ";
            }
            FOUT << endl;
        }
        FOUT.close();
        return true;
    }

    bool Create_Negative(){
        if(H < 0)
            return false;
        for(int r = 0; r < H; r++){
            for(int c = 0; c < W; c++)
                ImageData[r][c] = MaxGray - ImageData[r][c];
        }
        return true;
    }

    bool Mean_Filter(int FilterSize=3){
        // create a new image in memory
        // apply median filter and then copy the result
        // back to the same image
        if(H < 0)
            return false;
        vector<vector<int>> Temp;
        Create(Temp, H, W);
        for(int r = 0; r < H; r++){
            for(int c = 0; c < W ; c++){
                int k = 0;
                int SUM = 0;
                for(int i=r-FilterSize/2; i< r+FilterSize/2; i++){
                    for(int j= c-FilterSize/2; j< c+FilterSize/2; j++){
                        if(i >=0 && i < H && j >= 0 && j < W){
                            SUM+= ImageData[i][j];
                            k++;
                        }
                    }
                }
                Temp[r][c] = SUM/k;
            }
        }
        for(int r = 0; r < H; r++){
            for(int c = 0; c < W ; c++){
                ImageData[r][c] = Temp[r][c];
            }
        }
    }

    bool Median_Filter(int FilterSize=3){
        // create a new image in memory
        // apply median filter and then copy the result
        // back to the same image
        if(H < 0)
            return false;
        vector<vector<int>> Temp;
        Create(Temp, H, W);
        int D[100];
        for(int r = 0; r < H; r++){
            for(int c = 0; c < W ; c++){
                int k = 0;
                for(int i=r-FilterSize/2; i< r+FilterSize/2; i++){
                    for(int j= c-FilterSize/2; j< c+FilterSize/2; j++){
                        if(i >=0 && i < H && j >= 0 && j < W){
                            D[k] = ImageData[i][j];
                            k++;
                        }
                    }
                }
                B_Sort(D, k);
                Temp[r][c] = D[k/2];
            }
        }
        for(int r = 0; r < H; r++){
            for(int c = 0; c < W ; c++){
                ImageData[r][c] = Temp[r][c];
            }
        }
        return true;
    }

    bool Rotate(double angle) {
        vector<vector<int>> temp;
        Create(temp, H, W);
        for (int r = 0; r < H; r++) {
            for (int c = 0; c < W; c++) {
                int newr = r * cos(angle) + c * sin(angle);
                int newc = -r * sin(angle) + c * cos(angle);
                if (newr > 0 && newr < H && newc > 0 && newc < W)
                    temp[r][c] = ImageData[newr][newc];
            }
        }
        for (int r = 0; r < H; r++) {
            for (int c = 0; c < W; c++) {
                ImageData[r][c] = temp[r][c];
            }
        }
        return true;
    }

    bool RotateClockwise(){

        return true;
    }

    bool RotateCounterClockwise(){

        return true;
    }

    bool FlipHorizontal(){
        if(H < 0)
            return false;
            int a[255][255];

             for(int r = 0; r < H; r++){
                    int i=0;
            for(int c = W; c >=0; c--){
               a[r][i]=ImageData[r][c];
               i++;
        }
             }

             for(int r = 0; r < H; r++){
            for(int c = 0; c <W; c++){
               ImageData[r][c]=a[r][c];
        }
             }

    }

    bool FlipVertical(){
if(H < 0)
            return false;
            int a[255][255];

             for(int r = H; r >=0; r--){
                    int i=0;
            for(int c = 0; c <W; c++){

               a[i][c]=ImageData[r][c];

        }
 i++;
             }

             for(int r = 0; r < H; r++){
            for(int c = 0; c <W; c++){
               ImageData[r][c]=a[r][c];
        }
             }


    }

    bool Resize(int NewH, int NewW){

        return true;
    }

    bool CropImage(int Left, int Top, int Right, int Bottom){

        return true;
    }

    bool ApplyTransformation(double TrasformationMatrix[][3]){

        return true;
    }
};

int Menu(){
    int choice;
    do{
        cout<<endl<<"1. Load Image"<<endl
        <<"2. Save Image"<<endl
        <<"__________________________"<<endl
        <<"3. Create Negative Image"<<endl
        <<"__________________________"<<endl
        <<"4. Mean Filter"<<endl
        <<"5. Median Filter"<<endl
        <<"__________________________"<<endl
        <<"6. Flip Horizontal"<<endl
        <<"7. Flip Vertical"<<endl
        <<"8. Rotate Clockwise by 90 Degree"<<endl
        <<"9. Rotate Counter Clockwise by 90 degree"<<endl
        <<"10. Rotate By arbitrary angle"<<endl
        <<"11. Resize Image"<<endl
        <<"12. Apply general Linear Transformation"<<endl
        <<"13. Crop Image"<<endl
        <<"__________________________"<<endl
        <<"14. Exit"<<endl<<endl
        <<"Enter Your Choice: ";
        cin>> choice;
    } while(choice < 1 || choice > 14);
}

int main()
{
    PGMImage Image;

    char FileName[100];
    int Choice;

    do{
        Choice = Menu();
        if(Choice == 1){
            cout<<"Enter File Name ";
            cin>>FileName;
            if(Image.LoadImage(FileName) )
               cout<<"Image Loaded Successfully "<<endl;
            else
                cout<<"Image Not Loaded Successfully "<<endl;
        }
        else if(Choice == 2){
            cout<<"Enter File Name ";
            cin >> FileName;
            if(Image.SaveImage(FileName) )
               cout<<"Image Saved Successfully "<<endl;
            else
                cout<<"Image Not Saved Successfully "<<endl;

        }
        else if(Choice == 3){
            if(Image.H < 0)
                cout<<"No Image Loaded"<<endl;
            else
                Image.Create_Negative();
        }
        else if(Choice == 4){
            Image.Mean_Filter(5);
        }
        else if(Choice == 5){
            int S;
            cout<<"Filter Size ";
            cin>> S;
            Image.Median_Filter(S);
        }
        else if(Choice == 6){
                Image.FlipHorizontal();
        }
        else if(Choice == 7){
            Image.FlipVertical();
        }
        else if(Choice == 8){

        }
        else if(Choice == 9){

        }
        else if(Choice == 10){
 int S;
            cout<<"Enter Rotation Angle : ";
            cin>> S;
        Image.Rotate(S);
        }
        else if(Choice == 11){

        }
        else if(Choice == 12){

        }
        else if(Choice == 13){

        }

    }while(Choice != 14);

    return 0;
}
