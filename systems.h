#pragma once

enum class SubsystemMode: int
{
	Join = 0,
	Merge,
	Exclude,
};
template<typename T, SubsystemMode MODE>
	std::set<T> subsystem (const std::set<T> &A, const std::set<T> &B)
	{
		std::set<T> newset;
		if(MODE == SubsystemMode::Merge)
		{
			newset = B;
			for(auto& o: A) newset.insert(o);
		}
		else if(MODE == SubsystemMode::Exclude)
		{
			newset = B;
			for(auto& o: A) newset.erase(o);
		}
		else if(A.size() < B.size())
		{
			for(auto& o: A)
				if(B.find(o) != B.end()) newset.insert(o);
		}
		else
		{
			for(auto& o:B)
				if(A.find(o) != A.end()) newset.insert(o);
		}
		return newset;
	}




template<class T>
	std::set< T > join(
			const std::set<T> &A,
			const std::set<T> &B
	) { return subsystem<T,SubsystemMode::Join>(A,B);   }

template<class T>
	std::set< T > join(
			const std::set<T> &A,
			const std::set<T> &B,
			const std::set<T> &C
	) { return subsystem<T,SubsystemMode::Join>(A,join(B,C));   }

template<class T>
	std::set< T > exclude(
			const std::set<T> &A,
			const std::set<T> &B
	) { return subsystem<T,SubsystemMode::Exclude>(A,B); }
