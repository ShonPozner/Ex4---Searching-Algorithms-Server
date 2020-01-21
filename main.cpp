
namespace boot
{

  class Main {
   public:
    int main_part2(int port) {
      CacheManager<string, string> *cacheManager = new FileCacheManger();
      Solver<string,string> *slover = new StringReverser();
      ClientHandler *clientHand = new MyTestClientHandler(cacheManager,slover);
      Server *server = new MySerialServer();
      server->open(port,clientHand);
      return 0;
    }

    using namespace boot;
int main (int argc, char *argv[]){
  Main m;
  m.main_part2((stoi(argv[1]));
  return 0;
  //return m.main(stoi(argv[1]));
}
    
