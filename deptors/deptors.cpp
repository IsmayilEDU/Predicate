#include <iostream> 
using namespace std;
#include<list>

#include"class_Datetime.h"
#include"class_Deptor.h"

double averageDepts = 0;

namespace predicates
{
	bool selectEmailRhytaAndDayrep(const Deptor& deptor)
	{
		string Rhyta = "rhyta.com";
		string Dayrep = "dayrep.com";
		string emailDeptor = *deptor.get_email();
		string endEmail;

		for (int i = 0; i < emailDeptor.length(); i++)
		{
			if (emailDeptor[i] == '@')
			{
				endEmail = "";
				for (int j = i + 1; emailDeptor[j] != '\0'; j++)
				{
					endEmail += emailDeptor[j];
				}
				break;
			}
		}

		if (endEmail == Rhyta || endEmail == Dayrep)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool selectAge26And36(const Deptor& deptor)
	{
		short age = 2023 - (*deptor.get_birtday()).get_year();
		if (age > 26 && age < 36)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool selectDeptMoreThan(const Deptor& deptor)
	{
		if ((*deptor.get_dept()) < 5000)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool selectNameLengthMoreThan18And(const Deptor& deptor)
	{
		//  Length of fullname
		short length = (*deptor.get_fullname()).length();

		//  Get count of seven in telephone number
		int seven = 55;
		short count = 0;
		for (auto& i : *deptor.get_phoneNumber())
		{
			int symbol = int(i);
			if (symbol == seven)
			{
				count++;
			}
		}

		//  Select deptor
		if ((length > 18) && (count >= 2))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool selectBornInWinter(const Deptor& deptor)
	{
		short month = (*deptor.get_birtday()).get_month();

		if (month == 1 || month == 12 || month == 2)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool removeLessThanAverageDept(const Deptor& deptor)
	{
		if ((*deptor.get_dept()) > averageDepts)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool sortByDept(const Deptor& deptor1, const Deptor& deptor2)
	{
		return (*deptor1.get_dept()) > (*deptor2.get_dept());
	}

	bool selectDeptorThereIsNot8InTelephone(const Deptor& deptor)
	{
		//  Get count of eight in telephone number
		int eight = 56;
		short count = 0;
		for (auto& i : *deptor.get_phoneNumber())
		{
			int symbol = int(i);
			if (symbol == eight)
			{
				count++;
			}
		}

		//  Select deptor
		if (count == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool selectSame3letterİnFullname(const Deptor& deptor)
	{
		short countSame3letter = 0;
		for (auto& symbol1 : *deptor.get_fullname())
		{
			short countSymbol = 0;
			for (auto& symbol2 : *deptor.get_fullname())
			{
				if (symbol2 == symbol1)
				{
					countSymbol++;
				}
			}

			if (countSymbol >= 3)
			{
				countSame3letter++;
				break;
			}
		}

		if (countSame3letter > 0)
		{
			return false;
		}
		else
		{
			return true;
		}

	}

	bool sortByAlphabet(const Deptor& deptor1, const Deptor& deptor2)
	{
		int symbol1 = int((*deptor1.get_fullname())[0]);
		int symbol2 = int((*deptor2.get_fullname())[0]);
		if (symbol2 > symbol1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool selectSeenDeptor2WorldWar(const Deptor& deptor)
	{
		short yearOfBirth = (*deptor.get_birtday()).get_year();
		if (yearOfBirth >= 1941 && yearOfBirth <= 1945)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool selectDeptorNoRepeatedDigitİnTheNumber(const Deptor& deptor)
	{
		bool check = false;
		for (auto& mainNumber : *deptor.get_phoneNumber())
		{
			short countNumber = 0;
			for (auto& number : *deptor.get_phoneNumber())
			{
				if (number == mainNumber)
				{
					countNumber++;
				}
			}
			if (countNumber > 1)
			{
				check = true;
				return check;
			}
		}
		return check;
	}

	bool selectDeptorPayOffTheDebt(const Deptor& deptor)
	{
		short day;
		short deptorBirtday = ((*deptor.get_birtday()).get_month() * 30) + (*deptor.get_birtday()).get_day();
		//  85 il bashdiyannan olan gun sayidir
		if (deptorBirtday >= 85)
		{
			day = deptorBirtday - 85;
		}
		else
		{
			day = 365 - (85 - deptorBirtday);
		}

		if ((day * 500) >= (*deptor.get_dept()))
		{
			return false;
		}
		else
		{
			return true;
		}


	}

	bool selectDeptorCreateSMILE(const Deptor& deptor)
	{
		short countS = 0, countM = 0, countI = 0, countL = 0, countE = 0;
		bool check = true;
		for (auto& symbol : *deptor.get_fullname())
		{
			if (symbol == 's')
			{
				countS++;
			}
			if (symbol == 'm')
			{
				countM++;
			}
			if (symbol == 'i')
			{
				countI++;
			}
			if (symbol == 'l')
			{
				countL++;
			}
			if (symbol == 'e')
			{
				countE++;
			}
			if ((countS == 1) && (countM == 1) && (countI == 1) && (countL == 1) && (countE == 1))
			{
				check = false;
				break;
			}
		}

		if (check)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

namespace otherFunctions
{
	short findMaxCountBornDeptorsYear(const list<Deptor>& deptors)
	{
		short wantedYear;
		short countMAxYearOfBirth = 0;
		for (auto& mainDeptor : deptors)
		{
			short yearOfBirthMainDeptor = (*mainDeptor.get_birtday()).get_year();
			short countYearOfBirth = 0;
			for (auto& deptor : deptors)
			{
				short yearOfBirthDeptor = (*deptor.get_birtday()).get_year();
				if (yearOfBirthMainDeptor == yearOfBirthDeptor)
				{
					countYearOfBirth++;
				}
			}
			if (countYearOfBirth > countMAxYearOfBirth)
			{
				countMAxYearOfBirth = countYearOfBirth;
				wantedYear = yearOfBirthMainDeptor;
			}
		}
		return wantedYear;
	}

}



int main()
{
	list<Deptor> deptors =
	{
		Deptor("Shirley T. Qualls", Datetime(30,3,1932), "5306627732", "ShirleyTQualls@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414),
		Deptor("Danielle W. Grier", Datetime(18,10,1953), "3214734178", "DanielleWGrier@rhyta.com", "1973 Stoneybrook Road Maitland, FL 32751", 3599),
		Deptor("Connie W. Lemire", Datetime(18,6,1963), "8283213751", "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219),
		Deptor("Coy K. Adams", Datetime(1,5,1976), "4103471307", "CoyKAdams@dayrep.com", "2411 Blue Spruce Lane Baltimore, MD 21202", 3784),
		Deptor("Bernice J. Miles", Datetime(1,6,1988), "0123456789", "BerniceJMiles@armyspy.com", "4971 Austin Avenue Savannah, GA 31401", 4060),
		Deptor("Bob L. Zambrano", Datetime(28,2,1990), "7064461649", "BobLZambrano@armyspy.com", "2031 Limer Street Augusta, GA 30901", 6628),
		Deptor("Adam D. Bartlett", Datetime(6,5,1950), "6506931758", "AdamDBartlett@rhyta.com", "2737 Rardin Drive San Jose, CA 95110", 5412),
		Deptor("Pablo M. Skinner", Datetime(26,8,1936), "6303912034", "PabloMSkinner@armyspy.com", "16 Fraggle Drive Hickory Hills, IL 60457", 11097),
		Deptor("Dorothy J. Brown",Datetime(9,7,1971), "2704563288", "DorothyJBrown@rhyta.com", "699 Harper Street Louisville, KY 40202", 7956),
		Deptor("Larry A. Miracle",Datetime(22,5,1998), "3016213318", "LarryAMiracle@jourrapide.com", "2940 Adams Avenue Columbia, MD 21044", 7150),
		Deptor("Donna B. Maynard", Datetime(26,1,1944), "5202970575", "DonnaBMaynard@teleworm.us", "4821 Elk Rd Little Tucson, AZ 85704", 2910),
		Deptor("Jessica J. Stoops", Datetime(22,8,1989), "3603668101", "JessicaJStoops@dayrep.com", "2527 Terra Street Custer, WA 98240", 11805),
		Deptor("Audry M. Styles",Datetime(7,2,1937), "9787734802", "AudryMStyles@jourrapide.com", "151 Christie Way Marlboro, MA 01752", 1001),
		Deptor("Violet R. Anguiano",Datetime(4,11,1958), "5853407888", "VioletRAnguiano@dayrep.com", "1460 Walt Nuzum Farm Road Rochester, NY 14620", 9128),
		Deptor("Charles P. Segundo",Datetime(21,10,1970), "4153673341", "CharlesPSegundo@dayrep.com", "1824 Roosevelt Street Fremont, CA 94539", 5648),
		Deptor("Paul H. Sturtz", Datetime(15,9,1944), "3363761732", "PaulHSturtz@dayrep.com", "759 Havanna Street Saxapahaw, NC 27340", 10437),
		Deptor("Doris B. King", Datetime(6,5,1950), "2052318973", "DorisBKing@rhyta.com", "3172 Bedford Street Birmingham, AL 35203", 7230),
		Deptor("Deanna J. Donofrio", Datetime(16,4,1983), "9528427576", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515),
		Deptor("Martin s. Malemowski",Datetime(17,1,1992), "7655993523", "MartinSMalinowski@dayrep.com", "3749 Capitol Avenue New Castle, IN 47362", 1816),
		Deptor("Melissa R. Arner", Datetime(24,5,1974), "5305087328", "MelissaRArner@armyspy.com", "922 Hill Croft Farm Road Sacramento, CA 95814", 5037),
		Deptor("Kelly G. Hoffman", Datetime(22,9,1952), "5058768935", "KellyGHoffman@armyspy.com", "4738 Chapmans Lane Grants, NM 87020", 7755),
		Deptor("Doyle B. Short", Datetime(15,6,1963), "9892214363", "DoyleBShort@teleworm.us", "124 Wood Street Saginaw, MI 48607", 11657),
		Deptor("Lorrie R. Gilmore", Datetime(23,12,1963), "7243067138", "LorrieRGilmore@teleworm.us", "74 Pine Street Pittsburgh, PA 15222", 9693),
		Deptor("Lionel A. Cook", Datetime(16,4,1972), "2016275962", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712),
		Deptor("Charlene C. Burke", Datetime(18,1,1970), "4843349729", "CharleneCBurke@armyspy.com", "4686 Renwick Drive Philadelphia, PA 19108", 4016),
		Deptor("Tommy M. Patton", Datetime(30,1,1982), "7745716481", "TommyMPatton@rhyta.com", "748 Rockford Road Westborough, MA 01581", 349),
		Deptor("Kristin S. Bloomer", Datetime(16,6,1944), "4436520734", "KristinSBloomer@dayrep.com", "15 Hewes Avenue Towson, MD 21204", 9824),
		Deptor("Daniel K. James", Datetime(12,11,1997), "8014074693", "DanielKJames@rhyta.com", "3052 Walton Street Salt Lake City, UT 84104", 8215),
		Deptor("Paula D. Henry", Datetime(6,9,1976), "6183785307", "PaulaDHenry@rhyta.com", "3575 Eagle Street Norris City, IL 62869", 5766),
		Deptor("Donna C. Sandoval", Datetime(13,12,1947), "5404825463", "DonnaCSandoval@rhyta.com", "675 Jehovah Drive Martinsville, VA 24112", 8363),
		Deptor("Robert T. Taylor", Datetime(17,8,1932), "2705966442", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785),
		Deptor("Donna W. Alamo", Datetime(9,12,1948), "9787782533", "DonnaWAlamo@teleworm.us", "4367 Christie Way Marlboro, MA 01752", 10030),
		Deptor("Amy R. Parmer", Datetime(19,5,1995), "4808834934", "AmyRParmer@armyspy.com", "85 Elmwood Avenue Chandler, AZ 85249", 5347),
		Deptor("Newton K. Evans", Datetime(18,10,1986), "3032079084", "NewtonKEvans@rhyta.com", "3552 Columbia Road Greenwood Village, CO 80111", 9838),
		Deptor("Kathleen C. Chaney", Datetime(5,1,1949), "6052453513", "KathleenCChaney@rhyta.com", "316 Elsie Drive Fort Thompson, SD 57339", 1672),
		Deptor("Manuel C. Johnson", Datetime(13,2,1947), "6062472659", "ManuelCJohnson@jourrapide.com", "4146 May Street Sharpsburg, KY 40374", 9195),
		Deptor("Carla A. Creagh", Datetime(21,11,1988), "6143078974", "CarlaACreagh@dayrep.com", "3106 Bates Brothers Road Columbus, OH 43215", 11271),
		Deptor("Norma M. New", Datetime(18,5,1988), "8574928703", "NormaMNew@jourrapide.com", "965 Metz Lane Woburn, MA 01801", 9761),
		Deptor("Roy D. Green", Datetime(27,1,1983), "3083405981", "RoyDGreen@jourrapide.com", "401 Romrog Way Grand Island, NE 68801", 10771),
		Deptor("Cristy J. Jensen", Datetime(2,11,1935), "4406269550", "CristyJJensen@jourrapide.com", "2177 Harley Vincent Drive Cleveland, OH 44113", 5205),
		Deptor("Nancy J. Fergerson", Datetime(10,6,1983), "2199878498", "NancyJFergerson@dayrep.com", "3584 Jadewood Drive Demotte, IN 46310", 1276),
		Deptor("Dave N. Rodriguez", Datetime(21,1,1938), "2145402499", "DaveNRodriguez@rhyta.com", "1890 Poco Mas Drive Dallas, TX 75247", 9132),
		Deptor("James E. Denning", Datetime(4,5,1988), "5042898640", "JamesEDenning@jourrapide.com", "1444 Rose Avenue Metairie, LA 70001", 8176),
		Deptor("Richard M. Thomas", Datetime(13,2,1973), "5107353359", "RichardMThomas@jourrapide.com", "4454 Green Avenue Oakland, CA 94609", 7875),
		Deptor("Lakisha R. Forrest", Datetime(1,12,1956), "3348301181", "LakishaRForrest@armyspy.com", "3121 Quarry Drive Montgomery, AL 36117", 3088),
		Deptor("Pamela H. Beauchamp", Datetime(20,11,1959), "8015596347", "PamelaHBeauchamp@jourrapide.com", "3239 Tori Lane Salt Lake City, UT 84104", 6588)
	};

	//  2) rhyta.com ve ya dayrep.com domenlerinde emaili olan borclulari cixartmag
	//deptors.remove_if(predicates::selectEmailRhytaAndDayrep);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//  3) Yashi 26-dan 36-ya qeder olan borclulari cixartmag
	//deptors.remove_if(predicates::selectAge26And36);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  4) Borcu 5000-den cox olmayan borclularic cixartmag
	//deptors.remove_if(predicates::selectDeptMoreThan);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  5) Butov adi 18 simvoldan cox olan ve telefon nomresinde 2 ve ya 2-den cox 7 reqemi olan borclulari cixartmaq
	//deptors.remove_if(predicates::selectNameLengthMoreThan18And);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  7) Qishda anadan olan borclulari cixardmaq
	//deptors.remove_if(predicates::selectBornInWinter);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  8) Borcu, umumi borclarin orta borcunnan cox olan borclulari cixarmaq ve evvel familyaya gore sonra ise meblegin azalmagina gore sortirovka etmek
	/*for (auto& deptor : deptors)
	{
		averageDepts += (*deptor.get_dept());
	}
	averageDepts = averageDepts / double(deptors.size());
	deptors.remove_if(predicates::removeLessThanAverageDept);
	deptors.sort(predicates::sortByDept);*/
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  9) Telefon nomresinde 8 olmayan borclularin yalniz familyasin,yashin ve umumi borcun meblegin cixarmaq
	//deptors.remove_if(predicates::selectDeptorThereIsNot8InTelephone);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  11)Adinda ve familyasinda hec olmasa 3 eyni herf olan borclularin siyahisin cixarmaq ve onlari elifba sirasina gore sortirovka elemek
	/*deptors.remove_if(predicates::selectSame3letterİnFullname);
	deptors.sort(predicates::sortByAlphabet);*/
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  13)borclulardan en coxu hansi ilde dogulubsa hemin ili cixartmaq
	//cout<< otherFunctions::findMaxCountBornDeptorsYear(deptors);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//  14)Borcu en boyuk olan 5 borclunun siyahisini cixartmaq
	/*deptors.sort(predicates::sortByDept);
	auto startIter = deptors.begin();
	for (short i = 0; i < 5; i++, startIter++)
	{
		cout << *startIter<<endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//  15)Butun borcu olanlarin borcunu cemleyib umumi borcu cixartmaq
	/*double totalDepts = 0;
	for (auto& deptor : deptors)
	{
		totalDepts += (*deptor.get_dept());
	}
	cout << totalDepts << endl;*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//  16)2ci dunya muharibesin gormush borclularin siyahisi cixartmaq
	//deptors.remove_if(predicates::selectSeenDeptor2WorldWar);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  18)Nomresinde tekrar reqemler olmayan borclularin ve onlarin borcunun meblegin cixartmaq
	//deptors.remove_if(predicates::selectDeptorNoRepeatedDigitİnTheNumber);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  19)Tesevvur edek ki,butun borclari olanlar bugunden etibaren her ay 500 azn pul odeyecekler. Oz ad gunune kimi borcun oduyub qurtara bilenlerin siyahisin cixartmaq
	//deptors.remove_if(predicates::selectDeptorPayOffTheDebt);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//  20)Adindaki ve familyasindaki herflerden "smile" sozunu yaza bileceyimiz borclularin siyahisini cixartmaq
	//deptors.remove_if(predicates::selectDeptorCreateSMILE);
	/*for (auto& deptor : deptors)
	{
		cout << deptor << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






}
