#include <cctype>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

class Solve {
public:
  std::string Final;

  Solve(std::vector<std::string> &Object) {
    long long sum = 0;

    for (std::string &Line : Object) {
      bool OnlyWhitespace = true;
      for (char Character : Line) {
        if (!std::isspace(static_cast<unsigned char>(Character))) {
          OnlyWhitespace = false;
          break;
        }
      }
      if (OnlyWhitespace)
        continue;

      std::size_t LBracket = Line.find('[');
      std::size_t RBracket = Line.find(']', LBracket + 1);
      if (LBracket == std::string::npos || RBracket == std::string::npos)
        continue;

      std::string Pattern = Line.substr(LBracket + 1, RBracket - LBracket - 1);
      int LightCount = static_cast<int>(Pattern.size());

      long long Target = 0;
      for (int Index = 0; Index < LightCount; Index++) {
        if (Pattern[Index] == '#') {
          Target |= 1ll << Index;
        }
      }

      std::vector<long long> Buttons;
      std::size_t Search = RBracket + 1;

      while (true) {
        std::size_t Open = Line.find('(', Search);
        if (Open == std::string::npos)
          break;
        std::size_t Close = Line.find(')', Open + 1);
        if (Close == std::string::npos)
          break;

        std::string Inside = Line.substr(Open + 1, Close - Open - 1);
        for (char &Character : Inside) {
          if (Character == ',')
            Character = ' ';
        }

        std::stringstream Stream(Inside);
        long long Mask = 0;
        int Index;
        while (Stream >> Index) {
          if (Index >= 0 && Index < LightCount) {
            Mask |= 1ll << Index;
          }
        }

        Buttons.push_back(Mask);
        Search = Close + 1;
      }

      if (Target == 0)
        continue;
      if (Buttons.empty())
        continue;
      if (LightCount <= 0 || LightCount >= 63)
        continue;

      std::size_t StateCount = 1ull << LightCount;
      std::vector<int> Distance(StateCount, -1);
      std::queue<long long> Queue;

      long long Start = 0;
      Distance[Start] = 0;
      Queue.push(Start);

      int Answer = -1;

      while (!Queue.empty()) {
        long long Current = Queue.front();
        Queue.pop();

        if (Current == Target) {
          Answer = Distance[Current];
          break;
        }

        int NextDistance = Distance[Current] + 1;
        for (long long Mask : Buttons) {
          long long Next = Current ^ Mask;
          if (Distance[Next] == -1) {
            Distance[Next] = NextDistance;
            Queue.push(Next);
          }
        }
      }

      if (Answer >= 0) {
        sum += Answer;
      }
    }

    Final = std::to_string(sum);
  }
};
