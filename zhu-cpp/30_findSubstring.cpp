//
// Created by Oliver on 2021/4/9.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    map<string,int>flag_has;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> r;
        map<string,int>flag_has;
        for(auto w:words)
            flag_has[w]++;
        int len = words[0].size();
        int start=0,end=0;
        for(int mod=0;mod<len;mod++) {
            vector<string> sub;
            map<string,int>flag;
            for(auto w:words)
            {
                flag[w]++;
            }
            for (int i = 0; i +len <= s.length(); i += len) {
                sub.push_back(s.substr(mod+i,len));
            }
            int left = 0;
            int right = 0;
            int result = 0;
            while(left<=right&&right<sub.size())
            {
                if(flag[sub[right]])
                {
                    flag[sub[right]]--;
                    right++;
                    result++;
                    if(result == words.size())
                        r.push_back(mod+left*len);
                }
                else if(flag_has[sub[right]]==0)
                {
                    right++;
                    left = right;
                    if(result!=0) {
                        result = 0;
                        flag.clear();
                        for (auto w:words)
                            flag[w]++;
                    }
                }
                else
                {
                    flag[sub[left]]++;
                    result--;
                    left++;
                }
            }
        }
        return r;
    }
};

int main()
{
    vector<string> aa = {"bar","foo","the"};
    vector<int> r;
    string a ="barfoofoobarthefoobarman";
    string b = "xjpguhvytyjcknhjqkwelhjqbdgtwxgvgxbdeydxwozidiutuqafxjxaodtkdbfjyiocgtbfhcplmjggbgoarlcgpxssyadyiuapndwxhlitvoayvqzobbuqzpkzpqyzkaqzgmwnyghvvjtszuiawdtxufylvwkhzbhfpfsnmbkjkedlylowqjvkquxmsivrlewakrqysahfgmqhxgfqpbcgxaupkrhvwfviwngrqpwybohaxnsoqvwpxqehkncgvzqtpwkflidoznqwcjksehjdzpkjdmranhtcfejsopgncxjeguymbhpcwbmbpfbcnvhsbqnpftdjsonainoludqtgcwvjyywvhryxepfzuqsjgstthhqmxltbhokfojcvcavgqchmszvyupudykrvvmwedikrroptrmbjojvgkrheibjgnbdknboqjakbpbwgnyrbhmjtfqantjvgmaqcbhulhgowhkeukvxrkhnpznfvwcdldwnedjpkqfjxqnualruvahmcwrxuuafxwubzetmwyvtqkntvhnshwhjsyimujuthoxjuqvqqqmhazayipsqnzbfaktuvpocennadirvadcdeedpvvfixipxujtpajugwhhbsaxsfbvliaadwhmvqbsmmnenxavvhcxbcwwjxtvfuvlqdxlvafhpsnernznxemygiuqfonniiyanxnkzuuoohugvwvsajsirnyydnnnwnplkcwkyqamxvuurrmrafztuauzphmlvdzhfvrflurkpmfidtbgycbuevtufhhakgjrdbwqvqbmciwhbxpcbrwgmscrbjtmsffvgemdupryxphaoxcpobxcvbwwnrkfwscewqjsfcqerzffwjxmmwrhynelgosfiujenvwsxozpogwmrtbeqslqhrbnitsqpevcztxykynaemmvhnbzhnpogqeolyfdccfdxecjcrjidyelnhmvuclduprioylscswaxylbpvkvvqikxuhuytxtkqbapottgrvfphjgetdzjljigrcembzwsczjqsczlygcfpijkmktzvehmgoaknzcqylisnjdlqfshpbsdnndjrkxayykoxogxzqpoascsxubmytsljvuahucisowrccobudsuxuouoqimlaauxwxhqbpkqldsptwjyogviurymclyenueltlcvaollufcnbnmptjzqbycflcjyxnjsynnaealygpljdzzyjyomyrtjvchustnsgctkdgklwwubxvziwouuhpecslxmgmepoxbremcckzdhucqqqmlzcpcwcbilnmabkbtqpxszwvhtzzjslwrnntlsutdjgflsigkyfcxezexydiqrfigudsmalrjtwunfcxdibcmajjbotrfybmtfghftzqpxlcepcjxdmlgvwhjqarqcdlhltoeuettryyhahgfvsnqqucgxtzzykijfwpbcjvujvdjelqadeswawcxpdwpoeyvcqxfzubipetvpjxvpqtqmxpebotpuumxkjelffvwlosczpzrhsjwqycrmvihrugbgkolrjiezcgbtisbadzsbblqytzsqfvyrklitvmvxuyrcqufvvzwyloygnqwsmwjwitrdhobcmugcqnzlnwlykjeaadsmzekhxdlhsojekrjafinseysrjyrjblxbrjkrnvyflhjvasxfbkzhkraustdtfdwymhpzengqwqnxklelvetixvcpphjwkhuzokavxhlwzatjlxxjdqrbnvsccdypltqzdswcbhyaktmxrjgwbzxowqrzvpqgkiipaescoscymovfxebyfbpctgdoxvxidfxdjrfzmkxaavhabiyilpkevpvvksfpzetiwakkkjklgrlhblqnbctyuqtgkawjfrubrenenxpuqcdrptgsyctusmadnyospivhminahewxgzoxvxqtzjntxpymongdvdmknzkudirlhijchbxgkmbjcawsnevkikuvjgspolcyvlacmakymmiqmgibkensqiqbqiqfttdpgfrvfevsqdkelthwzuqpegqvqjakefbmkuhsyfmokwswpbsqwkfatyvjjxvncwzprjhpoteypywhcqxybfaufyfovbbaxcponygdrkeikarmrrmuwnqblvpiwsiuwzkkxqnqctbpusdnlqhhfxkssbapvllskvekmtcqndfhyjujbdtgafauhclenwwaucmiwoyjugqupmfspaarganpcztqxssruebqucbqirkzfsrwsrnardpvclnzfftblusgyvwgnjfudyrvpgwijngnatnfbihmebudwtjlerihrbchjartqzistxyufhikkdpiwauarejjfnsooljglsygpyaxhijrnyalywnsawdfkxtaidgvxgbmhdloougbsipteclezqljnejvjrtgzuvgygvoddrxlgqrjdxititgoeeavxiwrfdroahrdzoqfhhokgygormevsespnpjsscgukzxjopoxyfjedpuxeyswfnoucxmwbvqlwpwmgljestkviesoennjabfeauabpsnljjapwjvochmnngbrvodxribredttvihgthxsssivbwkodniaelyvvzpadkvasejnngfgbqdcmprpczqgmoejptlsdjvxpekdmslniqqufjmhieqwuufjntescbpthbyttjhdbzaiiosssioocvzrqdjugaonbmhxyqczpcixqarkkfaocaftfqnmsbbtqisoyvppxzoqbfclmdzpdgkiyxwqbymtiehjzyyzynrzutnhymwbvimvhkmiiadtekcgjafjpyikrvtqkrthzhcgsqrcquvxhxdsakbrkldbjwttnpcowgvqzotriqorotjqfmhpylthhocxdelcmiulwpdhgtywpkmuwvmugfbqtfpzlcdylxjhnoovkprzzdtvafqjmtbizqhmsmkdlwnykdtusmvrrpnswfbjacrbuaommysxwhyjktdfgzwzqlrmssxtwowqqkfclxchgcqqvwvdxudnhwbarzvnpregclknkowqqniojgtgayvhvyjozebpwhxasjncajuqydghjcplakuxlelkipbgwygrkvvkfqcdvlnenerpplpapcmatogqmnjyiekpwpvrakxpoqgfcxhtcutvicnwrwvbdhtbwovyaupolyunxdizxcvfgiezhbamitnhjkhjfxaqxwfuznuzppgxzkwilxuuskdewkpbhprenwbpkvobmubnfxwqwsmrepvbakejcwqpuregmukaplnuklmjgzamqxpqjualsqdmhjvvefxtskpeybngcpstmilweljwdoimyfhcmgxermlrpyxuqrnebycfmmbpamcyrlceszkllvedwbxmumqwktbyhdojrskidmoxmbizymeupbimnbiawlydoomfgyqmlgjzhuygifcagnmwowykhypyndfvcvhpetolpotztybclpyblwlvuctjhyflwoaajonydhawfbysrytewgztiucrvhdrydthsgixpkvwlwoeujlrpmkzhorcywvwzoftwnsoxoklkbrekcxcrjdyywcwszsupxnlngbmwmxgprmbvkdmthmrdqnyphsehhsuptilhiryzeauqdhjmtdsmqqbakihtcdjxluhtofsufpklwvxryrdrjhrtpyntdyqouxkideeitotrmtlkkqbuxsposchvaamxxyfccknyairmbczovaiuvzjneslguzdsxjwbvjzxsrmvvljqntlitwyxqldlkjfjsbkpnmohfaecnqtblgleelduwjhismtmqgdfurozusbhkwkweyckjihitosldozvuccovqppksxvrjtxhvitdrbwfvjkjkhdmjtkbizodyluietpzbifslbahnmqxuwmfpwjaxzdwkzeqstrweworaqypfrmznagewreuqjqaiwsdrkzvgpnignxnemotmuylmcheozhyvzbmjaksqzcyoclvozocvmnjrwofvvdswhhghtazucziekdulsxjgkszjieefkxcrekaxkatozbtmhnzbmihzdhinnmtzlxsrjtqtvjjwleksukvgucfzlnpbcianhthqoxllhuhuzsotejbanhazwpcyzcoixvanulydhgxganbeydgmminizphatxitsigmvfqdnplnfptdszrgieohvxirwskodqdyxvdkmpzresxyuoeevunsuxjqqthvkmthhxuvotnsoksiayovsboobzfttoofahmhggcucroqdgaeeqbzrppupunkkbpkldtrkymopcgvjgzpwaopsekjaxtlzixkltdxrrliurddzesxfjnzpzipwbcxlcjwvpwmghwabafcgyanjnmymupkxukiwvhtkdhrmdrnfxsmxszihogtixfirpsplzixcrorvigcfyqeqqmxeusoraylprccsnaveqobyueftullmxjstdjndhavacztpzqusevqybwtwhfihodctmpxvpswurpjthfllddlezfcjknsaquvcmsxdmvzemjztqkgtpsarzcalpunhqiledlipgjttsuolgvewpenohnbyjogzyrebeorlxmgshudnpjjgowwxlxxunfwmzapdqgonvuhcrkriubpkzljnlghymdmlfcqvkflfbsjsfbdbculdfwqscatqffdljuiubvbcqlxvmcwqwjvbhmwjmpcrufegbpackdhaoexcgvucgqfncbzqsbjniotkfvmpytspzprflmjrerhgugynhhapxvzcsosqhmhjbzqonaittpznvzaegctezvgrjaksorbsssghuqanhbaeadihfenfzvykwiekcgcualeubejlglpioyrwceddabnymrioznkbaoxdtgobsejicbeghhjhjyfvrqltfvufksifyxgsdrbhufncnyjywrvphgimddtnxbsxayqdsrkmyxonxantrilaqtouyhjvicvlclouebjeaxsyxftqqeqgaecynmwyqrjuexpiyymbxgzxmsnexgkxmpxabvytmhnsgeahepicxhbjbonywaxjrxlusjnhsazyfchlrpnqyqaahpadryoivzepkrwcuwdbykmrachasjazbbfsbtdwvhnfbkivgnwgxkxzmeahqagrbnlchqacaqjbatyigwoggnfvtfcjikclyoqheslgiuhiohswdickvihrpjaxtflttbaztlgcgpmwxhsapvmnfteueguylfrgiugbfmflduhadcdsxphellypuupfbjojduniiuwlqfothrmggvkthljdfakjjysoshzcevquceokvcqdxbxgoijtkucwuxknglrkghfjlvviznowqnfexqyhkcdfbquibnskvzviwstvfhuwubatraaedglgwfozujlpkgahategcacybcrtftxiziqxpfxjqibcrdlryqzasbaugrplmmvmwljnsgwkrznkcydaqdcjgcfmvuziguweifrcopnhpcrtcuwtzyegdjsadsklogryoibczqjquckwygrygxeliymlswyhfphtxkxzaipwmzvkhoiomobunnifmgorwwmvgjujtmhflcpvraldomzbahjmqzfovrjecgpvuwafzrcqrnvicwlceuqwuxkrqvxsdmpxjrfkihccxzmzvxdbuvxqshhkdhcgttgeklousqyrpkqnitocqoskvbuaiwjeppibcxwupumhfeupakrqylbwovyxujblalncilxaflhmrdbrpuiqhlmwgmvawyowjbzumyutldicilwxggnprblzoicmgqkqrjkfjgywjgbrsxoaderwffvvnxhunsmedwjpcklnqogklwmqaemijidyfnsvfezkclzgvntnbbypymfysugdemcjzuggbgqftqmofhbgjbvhqdhixqmbcomdktjnbzturhkwonfxpagffqpegdfitulgpwtsvoopvylklqjctsjaizfoemyyglexhxpeodtjdhtpzftuxdvfeavimtgvemslmkranljtsfkrkdmjghomjjxvedqislvevmekzndtsnlerznzidorolosqhciszmnoszngdhasuflvundybwommhetlpnlbczucochvczrjlmgyrgbnuncdtvpilamnbippkwnoyeajrijiokyizaosxddifpwiznxlmkbkpdvileqzqqkpqyjodoyifuseippuctgtwbbihthxktmarxqwmpgrjyytonpsgvldymnffwepqssjqigexovjntedjwvrtgwssjzzgepywhjorpsreoctjgwucrmyxksrurqcxhcuoliidbzhrbccjyxoplmovefrxxvvfxpvjzdmcevvfxyrvxfmkrcfxjzugurnsijdiormtmialirihyurryyohxlnucbmlmrvaihvwpyhzrrgqnxhlwysvjhplkdywutzebwaswjsoaygnwnyunqpwahkkkijhcilfgmxdvptwqzlmokicczycgkprtyyxijcoxbtvrmthlevcodetcexlpmckkcjunljlmegfrboeflgwqmpvrmgibiulmdgzqrmcvukmvatbmzxemozfafndpjpdmxdcqrglmsajttkhujniznncucfklunxtsbjkixyczhvuueofsxfhmhbpmnchdccxdmhnlhqkpneluuqotvvgcyxpmzyrdaojo";
    vector<string> bb = {"twjyogviurymclyenueltlcvao","tmilweljwdoimyfhcmgxermlrp","ikuvjgspolcyvlacmakymmiqmg","agrbnlchqacaqjbatyigwoggnf","mbzwsczjqsczlygcfpijkmktzv","vljqntlitwyxqldlkjfjsbkpnm","beqslqhrbnitsqpevcztxykyna","usqyrpkqnitocqoskvbuaiwjep","ibkensqiqbqiqfttdpgfrvfevs","wszsupxnlngbmwmxgprmbvkdmt","fpzetiwakkkjklgrlhblqnbcty","sxdmvzemjztqkgtpsarzcalpun","wceddabnymrioznkbaoxdtgobs","hpecslxmgmepoxbremcckzdhuc","ztuauzphmlvdzhfvrflurkpmfi","ptrmbjojvgkrheibjgnbdknboq","vgjujtmhflcpvraldomzbahjmq","ygormevsespnpjsscgukzxjopo","qdkelthwzuqpegqvqjakefbmku","hsazyfchlrpnqyqaahpadryoiv","ickvihrpjaxtflttbaztlgcgpm","hnshwhjsyimujuthoxjuqvqqqm","ejicbeghhjhjyfvrqltfvufksi","hustnsgctkdgklwwubxvziwouu","jrfzmkxaavhabiyilpkevpvvks","reuqjqaiwsdrkzvgpnignxnemo","wyloygnqwsmwjwitrdhobcmugc","fvwlosczpzrhsjwqycrmvihrug","ehmgoaknzcqylisnjdlqfshpbs","irvadcdeedpvvfixipxujtpaju","mcwrxuuafxwubzetmwyvtqkntv","lcjwvpwmghwabafcgyanjnmymu","hdloougbsipteclezqljnejvjr","hmrdqnyphsehhsuptilhiryzea","wunfcxdibcmajjbotrfybmtfgh","aeeqbzrppupunkkbpkldtrkymo","rbnvsccdypltqzdswcbhyaktmx","jqqthvkmthhxuvotnsoksiayov","uqtgkawjfrubrenenxpuqcdrpt","mvmwljnsgwkrznkcydaqdcjgcf","wcdldwnedjpkqfjxqnualruvah","bamitnhjkhjfxaqxwfuznuzppg","moxmbizymeupbimnbiawlydoom","xyfjedpuxeyswfnoucxmwbvqlw","aftfqnmsbbtqisoyvppxzoqbfc","zepkrwcuwdbykmrachasjazbbf","akjjysoshzcevquceokvcqdxbx","pcgvjgzpwaopsekjaxtlzixklt","zucziekdulsxjgkszjieefkxcr","jrnyalywnsawdfkxtaidgvxgbm","xpkvwlwoeujlrpmkzhorcywvwz","qzotriqorotjqfmhpylthhocxd","wymhpzengqwqnxklelvetixvcp","ceuqwuxkrqvxsdmpxjrfkihccx","iwstvfhuwubatraaedglgwfozu","ohfaecnqtblgleelduwjhismtm","ekaxkatozbtmhnzbmihzdhinnm","uvxhxdsakbrkldbjwttnpcowgv","vafhpsnernznxemygiuqfonnii","sbtdwvhnfbkivgnwgxkxzmeahq","gwhhbsaxsfbvliaadwhmvqbsmm","yueftullmxjstdjndhavacztpz","qgdfurozusbhkwkweyckjihito","hsyfmokwswpbsqwkfatyvjjxvn","gxtzzykijfwpbcjvujvdjelqad","schvaamxxyfccknyairmbczova","prpczqgmoejptlsdjvxpekdmsl","tpzbifslbahnmqxuwmfpwjaxzd","zmzvxdbuvxqshhkdhcgttgeklo","bapottgrvfphjgetdzjljigrce","qchmszvyupudykrvvmwedikrro","sorbsssghuqanhbaeadihfenfz","xpfxjqibcrdlryqzasbaugrplm","ftqqeqgaecynmwyqrjuexpiyym","qusevqybwtwhfihodctmpxvpsw","jekrjafinseysrjyrjblxbrjkr","kriubpkzljnlghymdmlfcqvkfl","ynelgosfiujenvwsxozpogwmrt","bwovyaupolyunxdizxcvfgiezh","dtnxbsxayqdsrkmyxonxantril","mvuziguweifrcopnhpcrtcuwtz","emmvhnbzhnpogqeolyfdccfdxe","drbwfvjkjkhdmjtkbizodyluie","dnlqhhfxkssbapvllskvekmtcq","pwhxasjncajuqydghjcplakuxl","jlpkgahategcacybcrtftxiziq","tzsqfvyrklitvmvxuyrcqufvvz","llvedwbxmumqwktbyhdojrskid","mflduhadcdsxphellypuupfbjo","eswawcxpdwpoeyvcqxfzubipet","elkipbgwygrkvvkfqcdvlnener","uiubvbcqlxvmcwqwjvbhmwjmpc","bxgzxmsnexgkxmpxabvytmhnsg","rjgwbzxowqrzvpqgkiipaescos","clvozocvmnjrwofvvdswhhghta","oftwnsoxoklkbrekcxcrjdyywc","ypyndfvcvhpetolpotztybclpy","qeqqmxeusoraylprccsnaveqob","ftzqpxlcepcjxdmlgvwhjqarqc","lknkowqqniojgtgayvhvyjozeb","puregmukaplnuklmjgzamqxpqj","banhazwpcyzcoixvanulydhgxg","ualsqdmhjvvefxtskpeybngcps","ynnaealygpljdzzyjyomyrtjvc","cjcrjidyelnhmvuclduprioyls","ubmytsljvuahucisowrccobuds","fyxgsdrbhufncnyjywrvphgimd","aelyvvzpadkvasejnngfgbqdcm","wnqblvpiwsiuwzkkxqnqctbpus","sldozvuccovqppksxvrjtxhvit","blwlvuctjhyflwoaajonydhawf","yanxnkzuuoohugvwvsajsirnyy","ihrbchjartqzistxyufhikkdpi","vobmubnfxwqwsmrepvbakejcwq","tmuylmcheozhyvzbmjaksqzcyo","tgzuvgygvoddrxlgqrjdxititg","pgwijngnatnfbihmebudwtjler","dxrrliurddzesxfjnzpzipwbcx","hqiledlipgjttsuolgvewpenoh","pwmgljestkviesoennjabfeaua","xzkwilxuuskdewkpbhprenwbpk","kyfcxezexydiqrfigudsmalrjt","pplpapcmatogqmnjyiekpwpvra","phjwkhuzokavxhlwzatjlxxjdq","gsyctusmadnyospivhminahewx","lmdzpdgkiyxwqbymtiehjzyyzy","kfwscewqjsfcqerzffwjxmmwrh","urpjthfllddlezfcjknsaquvcm","lnpbcianhthqoxllhuhuzsotej","qcbhulhgowhkeukvxrkhnpznfv","nrzutnhymwbvimvhkmiiadtekc","cymovfxebyfbpctgdoxvxidfxd","tzlxsrjtqtvjjwleksukvgucfz","hazayipsqnzbfaktuvpocennad","bpsnljjapwjvochmnngbrvodxr","hogtixfirpsplzixcrorvigcfy","vpjxvpqtqmxpebotpuumxkjelf","gjafjpyikrvtqkrthzhcgsqrcq","eahepicxhbjbonywaxjrxlusjn","gowwxlxxunfwmzapdqgonvuhcr","bmciwhbxpcbrwgmscrbjtmsffv","wauarejjfnsooljglsygpyaxhi","dqdyxvdkmpzresxyuoeevunsux","rufegbpackdhaoexcgvucgqfnc","fgyqmlgjzhuygifcagnmwowykh","nenxavvhcxbcwwjxtvfuvlqdxl","pkxukiwvhtkdhrmdrnfxsmxszi","vtfcjikclyoqheslgiuhiohswd","qnzlnwlykjeaadsmzekhxdlhso","cswaxylbpvkvvqikxuhuytxtkq","fqjmtbizqhmsmkdlwnykdtusmv","dnndjrkxayykoxogxzqpoascsx","kudirlhijchbxgkmbjcawsnevk","ibredttvihgthxsssivbwkodni","ndfhyjujbdtgafauhclenwwauc","dlhltoeuettryyhahgfvsnqquc","zfovrjecgpvuwafzrcqrnvicwl","wvhtzzjslwrnntlsutdjgflsig","cwzprjhpoteypywhcqxybfaufy","kxpoqgfcxhtcutvicnwrwvbdht","yxuqrnebycfmmbpamcyrlceszk","qtfpzlcdylxjhnoovkprzzdtva","ofsufpklwvxryrdrjhrtpyntdy","jakbpbwgnyrbhmjtfqantjvgma","elcmiulwpdhgtywpkmuwvmugfb","bgkolrjiezcgbtisbadzsbblqy","bysrytewgztiucrvhdrydthsgi","sboobzfttoofahmhggcucroqdg","goijtkucwuxknglrkghfjlvviz","fbsjsfbdbculdfwqscatqffdlj","fovbbaxcponygdrkeikarmrrmu","llufcnbnmptjzqbycflcjyxnjs","wygrygxeliymlswyhfphtxkxza","dnnnwnplkcwkyqamxvuurrmraf","uxuouoqimlaauxwxhqbpkqldsp","gzoxvxqtzjntxpymongdvdmknz","byttjhdbzaiiosssioocvzrqdj","dtbgycbuevtufhhakgjrdbwqvq","iuvzjneslguzdsxjwbvjzxsrmv","sjgstthhqmxltbhokfojcvcavg","qouxkideeitotrmtlkkqbuxspo","gemdupryxphaoxcpobxcvbwwnr","ipwmzvkhoiomobunnifmgorwwm","pvclnzfftblusgyvwgnjfudyrv","hgcqqvwvdxudnhwbarzvnpregc","yegdjsadsklogryoibczqjquck","qqqmlzcpcwcbilnmabkbtqpxsz","ugaonbmhxyqczpcixqarkkfaoc","jduniiuwlqfothrmggvkthljdf","nowqnfexqyhkcdfbquibnskvzv","niqqufjmhieqwuufjntescbpth","xssruebqucbqirkzfsrwsrnard","vykwiekcgcualeubejlglpioyr","zqonaittpznvzaegctezvgrjak","oeeavxiwrfdroahrdzoqfhhokg","wkzeqstrweworaqypfrmznagew","miwoyjugqupmfspaarganpcztq","uqdhjmtdsmqqbakihtcdjxluht","rerhgugynhhapxvzcsosqhmhjb","aqtouyhjvicvlclouebjeaxsyx","bzqsbjniotkfvmpytspzprflmj","nvyflhjvasxfbkzhkraustdtfd","rrpnswfbjacrbuaommysxwhyjk","nbyjogzyrebeorlxmgshudnpjj","wxhsapvmnfteueguylfrgiugbf","qdnplnfptdszrgieohvxirwsko","anbeydgmminizphatxitsigmvf","tdfgzwzqlrmssxtwowqqkfclxc"};
    Solution s;
    r = s.findSubstring(a,aa);
    for(auto i:r)
        cout << i << endl;
    cout<<"BB"<<endl;
    r = s.findSubstring(b,bb);
    for(auto i:r)
        cout << i << endl;
    return 1;
}



