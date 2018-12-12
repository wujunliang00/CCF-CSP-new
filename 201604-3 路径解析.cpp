#include <iostream>
#include <string>
using namespace std;
 
int main(){
	int num;
	string curDir;
	cin >> num >> curDir;
	getchar();
	for (int i = 0; i<num; i++){
		string line;
		getline(cin, line);
		int pos;
 
		// ��ӵ�ǰĿ¼
		if (line[0] != '/'){
			line = curDir + "/" + line;
		}
		if (line.size() == 0){
			line = curDir;
		}
 
		// ��ȥ���///
		while ((pos = line.find("//")) != -1){
			int count = 2;
			while (line[pos + count] == '/'){
				count++;
			}
			line.erase(pos, count - 1);
		}
 
		// ��ȥ../
		while ((pos = line.find("/../")) != -1){
			if (pos == 0){
				line.erase(pos + 1, 3);
			}
			else{
				int spos;
				spos = line.rfind("/", pos - 1);
				line.erase(spos, pos - spos + 3);
			}
		}
 
		// ��ȥ./
		while ((pos = line.find("/./")) != -1){
			line.erase(pos + 1, 2);
		}
		// ��ȥ���һ��/
		if (line.size()>1 && line[line.size() - 1] == '/')
			line.erase(line.size() - 1);
 
		cout << line << endl;
	}
	return 0;
}
/*
2
/d2/d3
////
/d1/../../d2
*/

