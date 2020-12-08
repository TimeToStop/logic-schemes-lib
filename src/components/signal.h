#pragma once

enum class SignalValue : int
{
	HIGH    =  1,
	LOW     =  0,
	NOT_SET = -1
};

class Signal
{
public:
	Signal(SignalValue = SignalValue::NOT_SET);
	Signal(const Signal&);
	~Signal();

	int			intValue()	const;
	SignalValue value()		const;

	void setValue(SignalValue);

	Signal& operator=(const Signal&);
	Signal& operator=(SignalValue);
	
	bool operator==(const Signal&);
	bool operator!=(const Signal&);

	Signal operator!();

	Signal operator&(const Signal&);
	Signal operator|(const Signal&);
	Signal operator^(const Signal&);

	Signal operator&(SignalValue);
	Signal operator|(SignalValue);
	Signal operator^(SignalValue);
	
	Signal& operator&=(const Signal&);
	Signal& operator|=(const Signal&);
	Signal& operator^=(const Signal&);

	Signal& operator&=(SignalValue);
	Signal& operator|=(SignalValue);
	Signal& operator^=(SignalValue);

private:
	SignalValue _value;
};

