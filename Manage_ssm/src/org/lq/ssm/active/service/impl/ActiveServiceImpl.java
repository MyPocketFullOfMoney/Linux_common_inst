package org.lq.ssm.active.service.impl;

import java.util.List;

import javax.annotation.Resource;

import org.lq.ssm.active.dao.ActiveDao;
import org.lq.ssm.active.service.ActiveService;
import org.lq.ssm.entity.Active;
import org.lq.ssm.util.dao.DictionoryDao;
import org.springframework.stereotype.Service;
@Service("activeServiceImpl")
public class ActiveServiceImpl implements ActiveService{
	@Resource(name="activeDao")
	private ActiveDao activeDao;
	@Resource(name="dictionoryDao")
	private DictionoryDao dictionoryDao;
	public void setActiveDao(ActiveDao activeDao) {
		this.activeDao = activeDao;
	}
	public void setDictionoryDao(DictionoryDao dictionoryDao) {
		this.dictionoryDao = dictionoryDao;
	}

	@Override
	public boolean delete(Integer id) {
		return activeDao.delete(id)>0;
	}

	@Override
	public List<Active> findAll() {
		return activeDao.findAll();
	}

	@Override
	public Active findById(Integer id) {
		return activeDao.findById(id);
	}

	@Override
	public boolean save(Active a) {
		return activeDao.save(a)>0;
	}

	@Override
	public boolean update(Active a) {
		return activeDao.update(a)>0;
	}
	@Override
	public int findSeq() {
		return activeDao.findSeq();
	}
	@Override
	public List<Active> findByCon(String name, Integer state) {
		return activeDao.findByCon(name, state);
	}

}
