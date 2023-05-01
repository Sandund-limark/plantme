#include <math.h>

#define NUM_ROWS 50
//#define NUM_COLS 4

int k = 3;

float temp;
float hum;
float lux;
float member_label;

float fan_speed;
float ac_value;

bool enabledUserPref = true;

int i = 0;



void setup() {
  Serial.begin(9600);
  Serial.println("Training started ...");
}

void loop() {
  //if (enabledUserPref)
  //{
    //x_train[i][0] = member_label;
    //x_train[i][1] = temp;
    //x_train[i][2] = hum;
    //x_train[i][3] = lux;

    //y_train[i][0] = fan_speed;
    //y_train[i][1] = ac_value;
    //i++;
  //} 
  float y_train[NUM_ROWS][2] = {
    {1,18.824333257552507},
    {5,20.322462170529583},
    {0,16.237766853414136},
    {1,17.113318244943844},
    {0,18.898950205889943},
    {2,21.029267981960967},
    {1,16.266680080554885},
    {3,23.326610576927557},
    {1,19.157657278794183},
    {5,24.59595752432567},
    {0,19.12729617207645},
    {2,22.402980290880386},
    {4,21.446992427147933},
    {0,18.321637812622363},
    {0,16.741133451696044},
    {1,16.198515144356215},
    {4,24.224020960421342},
    {5,20.42505549482257},
    {2,23.209866725393063},
    {1,19.529585680009284},
    {0,17.484170917882345},
    {4,22.616403961079513},
    {0,16.56213878831098},
    {2,22.874364141496024},
    {2,20.45649449197468},
    {4,20.59580979714936},
    {1,19.202273313320276},
    {0,18.363740415505806},
    {1,19.68154981009162},
    {2,21.689969424617004},
    {1,19.452327200375578},
    {3,23.04514567317097},
    {3,22.81669814209735},
    {2,21.208371053872508},
    {0,17.543303456641052},
    {5,24.629058916851918},
    {5,22.825904453524412},
    {4,24.230091335394214},
    {2,21.71348059843073},
    {1,18.995025474169342},
    {5,24.68662079484692},
    {2,24.359371458285402},
    {3,24.141049399559172},
    {0,19.333597156634617},
    {0,19.506835359190273},
    {0,16.509538518152326},
    {1,17.824980498140917},
    {2,22.099479544717706},
    {0,19.637149631701735},
    {1,18.215361308986196}};

  float x_train[NUM_ROWS][4] = {
    {1,38,27.30333160501536,76.49419267380084},
    {0,76,28.779655219901045,51.73675327705011},
    {0,6,26.63583869393817,59.913775694336906},
    {1,8,28.048189467971994,61.818421332205475},
    {0,13,26.613467030610124,56.74422930197717},
    {0,86,29.279395793838045,48.54259178147187},
    {0,22,26.94736497118887,57.96815821656898},
    {0,68,29.809254823236103,63.130585216130235},
    {1,16,28.797377671696896,74.01172870344735},
    {0,77,27.363911736031987,41.44382155445922},
    {0,5,28.983146608218462,68.68119603677557},
    {1,95,27.315158140853047,54.25938322021612},
    {1,81,29.31103476157802,62.411182620239515},
    {1,33,28.515597225727415,56.151195672554415},
    {0,22,26.50395792187494,74.75921983650699},
    {1,40,26.562060000327055,66.20724470145169},
    {0,64,27.003717760306856,49.268069023738},
    {1,75,28.85559395603517,64.11707297453611},
    {1,91,28.90138051800711,53.63004535875559},
    {0,8,26.42278692267701,54.91728014226873},
    {0,24,26.8133988499639,65.28266164691122},
    {1,60,28.936266421781678,46.18732483487287},
    {1,11,27.180904370604274,57.60283873651525},
    {1,83,29.18010970226731,60.131376148622024},
    {0,71,29.58940082807005,49.021043668759305},
    {0,69,28.033767631831147,43.35845437502179},
    {0,22,28.705998104276496,61.68970952131106},
    {1,4,26.958967154642792,67.62332173099654},
    {1,27,26.956250654314854,58.61358929501843},
    {1,76,29.837720629494736,47.819783756453305},
    {1,17,28.23306994614635,60.8512619324697},
    {0,93,29.19584809195768,68.11120143686139},
    {0,72,29.665148664202793,44.718964456588125},
    {0,69,29.007509350825586,60.058221139797354},
    {1,9,26.330113687983104,64.52957074058956},
    {0,94,28.432862254773507,47.665522046208665},
    {0,99,28.627004390554035,66.36171266071315},
    {1,64,27.205886123937496,41.69384461408787},
    {0,86,28.332009387355008,52.185117339810105},
    {1,35,26.72917462763081,53.391207020267395},
    {1,86,29.949719765009878,68.96302791590995},
    {0,77,28.247051983327417,53.4071009171914},
    {0,70,27.444874548851583,66.39759523320785},
    {1,17,28.808989860257977,52.31962564166293},
    {1,16,26.117449609118996,73.25842291980103},
    {1,9,26.8576660991508,53.01641031585041},
    {0,30,27.61941207507082,78.16549369829639},
    {1,63,28.753781529481603,53.57264543221636},
    {1,5,28.697260343894644,74.27363834673686}};
  
  i = NUM_ROWS;
  if (i >= NUM_ROWS)
  {

    delay(10000);
    randomSeed(analogRead(0));
    int n_train = NUM_ROWS;
    float n_test = NUM_ROWS * (10 / 100);
    int dist[n_train]; 

    float test_indices[int(n_test)][2];
    int x;
    for (int i = 0; i < int(n_test); i++) {
      x = random(NUM_ROWS);
      test_indices[i][0] = x_train[x][0];
      test_indices[i][1] = x_train[x][1];
    }
    // Find the k nearest neighbors
    for (int i = 0; i < k; i++) {
      int minDistIndex = i;
      for (int j = i + 1; j < n_train; j++) {
        if (dist[j] < dist[minDistIndex]) {
          minDistIndex = j;
        }
      }

      // Swap the distances and labels
      int tmpDist = dist[i];
      dist[i] = dist[minDistIndex];
      dist[minDistIndex] = tmpDist;
      float tmpLabel0 = y_train[i][0];
      float tmpLabel1 = y_train[i][1];
      y_train[i][0] = y_train[minDistIndex][0];
      y_train[i][1] = y_train[minDistIndex][1];
      y_train[minDistIndex][0] = tmpLabel0;
      y_train[minDistIndex][1] = tmpLabel1;
    }
    // Find the majority label
    float count0 = 0;
    float count1 = 0;
    float sum0 = 0;
    float sum1 = 0;
    for (int i = 0; i < k; i++) {
      sum0 += y_train[i][0];
      sum1 += y_train[i][1];
    }
    float prediction0 = sum0 / k;
    float prediction1 = sum1 / k;

    Serial.println("Test data.. ");
    Serial.print("Fan Speed Prediction: ");
    Serial.println(prediction0);
    Serial.print("a/C value Prediction: ");
    Serial.println(prediction1);
  } 
}





















