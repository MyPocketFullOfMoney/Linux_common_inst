package org.lq.ssm.admissions.service.impl;

import java.util.List;

import javax.annotation.Resource;

import org.lq.ssm.admissions.dao.AuditionDao;
import org.lq.ssm.admissions.service.AuditionBiz;
import org.lq.ssm.entity.Audition;
import org.springframework.stereotype.Service;

@Service("auditionBizImpl")
public class AuditionBizImpl implements AuditionBiz {

	@Resource(name="auditionDao")
	private AuditionDao auditionDao;

	@Override
	public boolean delete(int id) {

		return auditionDao.delete(id)>0;
	}

	@Override
	public List<Audition> findAll() {
		return auditionDao.findAll();
	}

	@Override
	public List<Audition> getByCouse(String couse) {
		return auditionDao.getByCouse(couse);
	}

	

	@Override
	public boolean save(Audition a) {
		return auditionDao.save(a)>0;
	}

	

	@Override
	public Audition getById(int id) {
		// TODO Auto-generated method stub
		return auditionDao.getById(id);
	}

	@Override
	public List<Audition> getByName(String name) {
		// TODO Auto-generated method stub
		return auditionDao.getByName(name);
	}

	@Override
	public List<Audition> getNC(String name, String couse) {
		// TODO Auto-generated method stub
		return auditionDao.getNC(name, couse);
	}

	public AuditionDao getAuditionDao() {
		return auditionDao;
	}

	public void setAuditionDao(AuditionDao auditionDao) {
		this.auditionDao = auditionDao;
	}

	@Override
	public boolean update(Audition a) {
		return auditionDao.update(a)>0;
	}

}
