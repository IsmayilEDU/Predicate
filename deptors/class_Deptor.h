#pragma once

class Deptor
{

private:

	string* _fullname = nullptr;
	Datetime* _birtday = nullptr;
	string* _phoneNumber = nullptr;
	string* _email = nullptr;
	string* _adress = nullptr;
	double* _dept = nullptr;

public:

	//	Get method of fullname
	const string* get_fullname() const
	{
		return this->_fullname;
	}

	//	Get method of birtday
	const Datetime* get_birtday() const
	{
		return this->_birtday;
	}

	//	Get method of phoneNumber
	const string* get_phoneNumber() const
	{
		return this->_phoneNumber;
	}

	//	Get method of email
	const string* get_email() const
	{
		return this->_email;
	}

	//	Get method of adress
	const string* get_adress() const
	{
		return this->_adress;
	}

	//	Get method of dept
	const double* get_dept() const
	{
		return this->_dept;
	}

	//	Set method of fullname
	void set_fullname(const string& fullname)
	{
		//	Check empty this->_fullname
		if (this->_fullname != nullptr)
		{
			delete this->_fullname;
		}

		this->_fullname = new string(fullname);
	}

	//	Set method of birtday
	void set_birtday(const Datetime& birtday)
	{
		//	Check empty this->_birtday
		if (this->_birtday != nullptr)
		{
			delete this->_fullname;
		}

		this->_birtday = new Datetime(birtday);
	}

	//	Set method of phoneNumber
	void set_phoneNumber(const string& phoneNumber)
	{
		//	Check empty this->_phoneNumber
		if (this->_phoneNumber != nullptr)
		{
			delete this->_phoneNumber;
		}

		this->_phoneNumber = new string(phoneNumber);
	}

	//	Set method of email
	void set_email(const string& email)
	{
		//	Check empty this->_email
		if (this->_email != nullptr)
		{
			delete this->_email;
		}

		this->_email = new string(email);
	}

	//	Set method of adress
	void set_adress(const string& adress)
	{
		//	Check empty this->_adress
		if (this->_adress != nullptr)
		{
			delete this->_adress;
		}

		this->_adress = new string(adress);
	}

	//	Set method of dept
	void set_dept(const double& dept)
	{
		//	Check empty this->_dept
		if (this->_dept != nullptr)
		{
			delete this->_dept;
		}

		this->_dept = new double(dept);
	}

	//	Constructor with parameters
	Deptor(const string& fullname, const Datetime& birtday, const string& phoneNumber, const string& email, const string& adress, const double& dept)
	{
		set_fullname(fullname);
		set_birtday(birtday);
		set_phoneNumber(phoneNumber);
		set_email(email);
		set_adress(adress);
		set_dept(dept);
	}

	//	Copy constructor
	Deptor(const Deptor& deptor)

	{
		this->set_fullname(*deptor._fullname);
		this->set_birtday(*deptor._birtday);
		this->set_phoneNumber(*deptor._phoneNumber);
		this->set_email(*deptor._email);
		this->set_adress(*deptor._adress);
		this->set_dept(*deptor._dept);
	}

	//	Operator <<
	friend ostream& operator <<(ostream& output, const Deptor& deptor)
	{
		output << "Fullname: " << *deptor._fullname << endl
			<< "Birthday: " << (*deptor._birtday).get_day() <<'/' << (*deptor._birtday).get_month() <<'/'<< (*deptor._birtday).get_year() << endl
			<< "Phone number: " << *deptor._phoneNumber << endl
			<< "Email: " << *deptor._email << endl
			<< "Adress: " << *deptor._adress << endl
			<< "Dept: " << *deptor._dept << endl;

		return output;
	}

	//	Destructor
	~Deptor()
	{
		delete this->_fullname;
		delete this->_birtday;
		delete this->_phoneNumber;
		delete this->_email;
		delete this->_adress;
		delete this->_dept;
	}

};