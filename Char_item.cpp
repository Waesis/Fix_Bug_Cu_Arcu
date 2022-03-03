Search : if (Cell.IsEquipPosition() && !CanUnequipNow(item))

Add :
#ifdef Fix_bug_arc

	if (GetWear(WEAR_WEAPON) && GetQuestFlag("timer_skill_ninja") && get_global_time() < GetQuestFlag("timer_skill_ninja"))
	{
		ChatInfoTrans(("In %d secunde poti dezechipa arma."), (GetQuestFlag("timer_skill_ninja") - get_global_time()) % 60);
		return false;
	}
#endif 

Search : bool CHARACTER::UnequipItem(LPITEM item)

Search: 	
	if (false == CanUnequipNow(item))
		return false;

Add :
#ifdef Fix_bug_arc
	 if (GetWear(WEAR_WEAPON) && GetQuestFlag("timer_skill_ninja") && get_global_time() < GetQuestFlag("timer_skill_ninja"))
	 {
		ChatInfoTrans(("In %d secunde poti dezechipa arma."), (GetQuestFlag("timer_skill_ninja") - get_global_time()) % 60);
		return false;
	 }
	
#endif