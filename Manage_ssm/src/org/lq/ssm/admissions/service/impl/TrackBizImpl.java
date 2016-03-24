package org.lq.ssm.admissions.service.impl;

import java.util.List;

import javax.annotation.Resource;

import org.lq.ssm.admissions.dao.TrackDao;
import org.lq.ssm.admissions.service.TrackBiz;
import org.lq.ssm.entity.Staff;
import org.lq.ssm.entity.Track;
import org.lq.ssm.util.dao.DictionoryDao;
import org.springframework.stereotype.Service;
@Service("trackBizImpl")
public class TrackBizImpl implements TrackBiz {
    @Resource(name="trackDao")
	private TrackDao trackDao;
    @Resource(name="dictionoryDao")
    private DictionoryDao dictionoryDao;
    
	@Override
	public boolean delete(int id) {
		return trackDao.delete(id)>0;
	}

	@Override
	public List<Track> findAll() {
		return trackDao.findAll();
	}

	@Override
	public List<Track> getByEnrollment(String Enrollment) {
		return trackDao.getByEnrollment(Enrollment);
	}

	@Override
	public List<Track> getByName(String name) {
		return trackDao.getByName(name);
	}

	@Override
	public boolean save(Track t) {
		return trackDao.save(t)>0;
	}

	@Override
	public boolean update(Track t) {
		return trackDao.update(t)>0;
	}

	public TrackDao getTrackDao() {
		return trackDao;
	}

	public void setTrackDao(TrackDao trackDao) {
		this.trackDao = trackDao;
	}

	public DictionoryDao getDictionoryDao() {
		return dictionoryDao;
	}

	public void setDictionoryDao(DictionoryDao dictionoryDao) {
		this.dictionoryDao = dictionoryDao;
	}

	@Override
	public Track getById(int id) {
		
		return trackDao.getById(id);
	}
	

}
