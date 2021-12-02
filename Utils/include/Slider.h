class Slider
{
public:
	Slider() { first = 0; second = 0; third = 0; }
	inline void SetFirst(uint32_t set) { first = set; }
	inline void SetSecond(uint32_t set) { second = set; }
	inline void SetThird(uint32_t set) { third = set; }

	inline uint32_t GetSum() const { return first + second + third; }
	inline void SlideWindow(uint32_t nextAmount) { first = second; second = third; third = nextAmount; }
private:
	uint32_t first;
	uint32_t second;
	uint32_t third;
};
